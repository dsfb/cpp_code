#include "paint.h"

#ifdef __MINGW32__
#include "freeglut.h"
#include "glut.h"
#include <windows.h>
#else
#include <GL/freeglut.h>
#include <GL/glut.h>
#endif

#include <cmath>
#include <string>

using namespace std;

#define WINDOW_WIDTH 800 // szerokość (x)
#define WINDOW_HEIGHT 600 // wysokość (y)

#define MENU_ITEM_UNDO 0
#define MENU_ITEM_SET_MODE 1
#define MENU_ITEM_FINISH 2
#define MENU_ITEM_RESTORE 3
#define MENU_ITEM_REMOVE_ALL 4

Paint paint;
Point futurePoint;
ArcInfo futureArc;
bool isLine;

void MouseClickEvent(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || paint.IsFinish)
        return;
    if (state != GLUT_DOWN)
        return;
    paint.ClearHistory();

    // для случая когда точек нет вообще
    if (paint.empty()) {
        paint.emplace_back();
        paint.back().a->x = x;
        paint.back().a->y = WINDOW_HEIGHT - y;
        paint.back().b = nullptr;
    }
    // для случая когда первый элемент не окончен
    else if (paint.IsFirstElement()) {
        paint.back().b = PointWrapper(new Point);
        paint.back().b->x = x;
        paint.back().b->y = WINDOW_HEIGHT - y;
    }
    // для остальных случаев
    else {
        auto lastB = (*(--paint.end())).b;
        paint.emplace_back();
        paint.back().a = lastB;
        paint.back().b->x = x;
        paint.back().b->y = WINDOW_HEIGHT - y;
    }
    if (paint.CurrentMode == Mode::Arc && !isLine) {
        paint.back().type = ElementType::Arc;
        paint.back().arcInfo = futureArc;
    }
    glutPostRedisplay();
};

void MenuClickEvent(int itemId)
{
    switch (itemId) {
    case MENU_ITEM_SET_MODE:
        // номер записи, метка, index selected
        if (paint.CurrentMode == Mode::Line
            && !paint.empty()) {
            glutChangeToMenuEntry(itemId + 1, "Tryb linii", MENU_ITEM_SET_MODE);
            paint.CurrentMode = Mode::Arc;
        } else {
            paint.CurrentMode = Mode::Line;
            glutChangeToMenuEntry(itemId + 1, "Tryb łuku", MENU_ITEM_SET_MODE);
        }
        break;
    case MENU_ITEM_UNDO:
        if (paint.CurrentMode == Mode::Line || (paint.CurrentMode == Mode::Arc && paint.size() > 1))
            paint.Back();
        glutPostRedisplay();
        break;
    case MENU_ITEM_FINISH:
        if (paint.IsFinish) {
            glutChangeToMenuEntry(itemId + 1, "Skończyć wielolinie", MENU_ITEM_FINISH);
            paint.IsFinish = false;
        } else {
            glutChangeToMenuEntry(itemId + 1, "Kontynuować", MENU_ITEM_FINISH);
            paint.IsFinish = true;
        }
        break;
    case MENU_ITEM_RESTORE:
        paint.Restore();
        break;
    case MENU_ITEM_REMOVE_ALL:
        paint.RemoveAll();
        break;
    }
}

void MouseMoveEvent(int x, int y)
{
    futurePoint.x = x;
    futurePoint.y = WINDOW_HEIGHT - y;
    glutPostRedisplay();
}

void DrawPoint(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void DrawLine(const Element& elem)
{
    glBegin(GL_LINES);
    glVertex2f(elem.a->x, elem.a->y);
    glVertex2f(elem.b->x, elem.b->y);
    glEnd();
}

// Функция для определения положения смещения
CirclePart GetCirclePart(bool IsLeftSide, float shift)
{
    if (shift >= 0 && shift <= 90 && IsLeftSide) /* O\ */
        return CirclePart::BetweenZeroAndOne;
    else if (shift >= 0 && shift <= 90 && !IsLeftSide)
        return CirclePart::BetweenThreeAndFour; /* O/ */

    else if (shift >= 90 && shift <= 180 && !IsLeftSide)
        return CirclePart::BetweenOneAndTwo; /* /O */
    else /*if (shift > 90 && shift <= 180 && IsLeftSide)*/
        return CirclePart::BetweenTwoAndThree; /* \O */
}

/*
Ta metoda rysuje łuk i ma następne argumenty:
AB - ostatni element wielolinii
aABF - to jest kąt między AB i BF, gdzie F - jest przyszły punkt
aBOF - to jest kąt między BO i OF, gdzie O - środek okręgu
r - to po prostu promień okręgu
o - współrzędne środku okręgu
*/
void DrawArc(Element& AB, float aABF, float aBOF, float r, Point o)
{
    float aAB = AB.GetAngleX();
    float shift = ConvertToDegrees(acos((AB.b->x - o.x) / r));
    //auto circlePart = GetCirclePart(AB.IsLeftSide(), shift);
    //cout << "circlePart: " << (unsigned short)circlePart << endl;
    bool isLeftSide = AB.IsLeftSide();
    float gamma = 0;
    float x = 0, y = 0;

    glBegin(GL_LINE_STRIP);
    for (float a = 0; a <= aBOF; a += 0.5f) {
        if (aAB > 0 && aABF > 0) // AB(UP, LEFT)
        {
            if (isLeftSide)
                gamma = a + shift;
            else
                gamma = a - shift; // 4 and false ->0/
        } else if (aAB > 0 && aABF < 0) // AB(UP, RIGHT)
        {
            if (isLeftSide)
                gamma = (360. - shift) - a;
            else
                gamma = (360. + shift) - a; // 2 and false /0
        } else if (aAB <= 0 && aABF < 0) // AB(DOWN, LEFT)
        {
            if (isLeftSide)
                gamma = (360. - a) + shift;
            else
                gamma = (360. - a) - shift; // 4 and false 0/
        } else if (aAB <= 0 && aABF > 0) // AB(DOWN, RIGHT)
        {
            if (isLeftSide)
                gamma = (360. - shift) + a;
            else
                gamma = a + shift;
        }

        x = r * cos(ConvertToRadians(gamma)) + o.x;
        y = r * sin(ConvertToRadians(gamma)) + o.y;
        glVertex2f(x, y);
    }
    glEnd();
}

// Функция отрисовки
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // покидаю функцию если нечего рисовать
    if (paint.empty()) {
        glFlush();
        return;
    };

    // строю контрольные точки
    glBegin(GL_POINTS);
    for (auto elem = paint.begin(); elem != paint.end(); elem++) {
        if ((*elem).a)
            glVertex2f((*elem).a->x, (*elem).a->y);
        if ((*elem).b)
            glVertex2f((*elem).b->x, (*elem).b->y);
    }
    glEnd();

    // строю целые элементы
    /*if (paint.CurrentMode == Mode::Line)
	{
		glBegin(GL_LINES);
		for (auto elem = paint.begin(); elem != paint.end(); elem++)
		{
			if ((*elem).b == nullptr) break;
			glVertex2f((*elem).a->x, (*elem).a->y);
			glVertex2f((*elem).b->x, (*elem).b->y);
		}
		glEnd();
	}*/
    //else
    //{

    auto elem = paint.begin();

    for (int i = 1; i <= (int)paint.size(); i++) {
        if ((*elem).type == ElementType::Arc && i > 1) {
            auto prev = --elem;
            elem++;
            DrawArc(*(prev), (*elem).arcInfo.aABF, (*elem).arcInfo.aBOF,
                (*elem).arcInfo.r, (*elem).arcInfo.o);
        } else {
            if ((*elem).b == nullptr)
                break;
            DrawLine(*elem);
        }
        elem++;
    } // end for
    //} // end if

    if (paint.IsFinish) {
        glFlush();
        return;
    };

    // процесс разработки нового элемента
    if (paint.CurrentMode == Mode::Line) {
        // рисую будущий элемент
        glBegin(GL_LINES);
        if (!paint.IsFirstElement())
            glVertex2f(paint.back().b->x, paint.back().b->y);
        else
            glVertex2f(paint.back().a->x, paint.back().a->y);
        glVertex2f(futurePoint.x, futurePoint.y);
        glEnd();
    } else {
        // начальные и конечные координаты будущего отрезка
        float bx = paint.back().b->x;
        float by = paint.back().b->y;
        float fx = futurePoint.x;
        float fy = futurePoint.y;

        // координаты точки делящей хорду на пополам
        float cx = (bx + futurePoint.x) / 2.0f;
        float cy = (by + futurePoint.y) / 2.0f;
        // определяем длину хорды
        //float hordaLen = VectorLenght(bx, by, fx, fy);
        // угол наклона хорды
        //float angle = ConvertToDegrees(atan2(fy - by, fx - bx));

        // cięciwa BF
        const Element BF(bx, by, fx, fy);
        // znajduję kąt między AB i BF
        float aABF = ConvertToDegrees(paint.back() ^ BF);

        //////////////////////////////////////////////////////////////

        Element vector1 = Element(paint.back().b);
        Element vector2 = Element(cx, cy, cx + 1000, cy);

        // нахожу углы наклона AB & BF относительно оси X
        float aAB = paint.back().GetAngleX();
        float aBF = BF.GetAngleX();

        // определяю углы поворота векторов
        float angle1 = 0;
        float angle2 = 90.0f + aBF;

        if (aAB < 0 && aABF < 0) {
            angle1 = -(90.0f + abs(aAB));
        } else if (aAB < 0 && aABF > 0) {
            angle1 = 90.0f + (180 - abs(aAB));
        } else if (aAB > 0 && aABF < 0) {
            angle1 = 90.0f - (180 - aAB);
        } else if (aAB > 0 && aABF > 0) {
            angle1 = 90.0f + aAB;
        } else {
            //cout << "aAB = 0; " << endl;
            if (aBF < 0)
                angle1 = -90;
            else
                angle1 = 90;
        }

        vector1.Rotate(ConvertToRadians(angle1));
        vector2.Rotate(ConvertToRadians(angle2));

        //cout << "<AB: " << aAB << endl;
        //cout << "<ABF: " << aABF << endl;
        //cout << "<horda BF: " << aBF << endl;
        //cout << "<angle1: " << angle1 << endl;
        //cout << "<angle2: " << angle2 << endl;

        float wynik = vector1 * vector2;
        if (wynik == 0.f) {
            isLine = true;
            DrawLine(BF);
            glFlush();
            return;
        } else
            isLine = false;

        float a1 = vector1.b->y - vector1.a->y;
        float b1 = vector1.a->x - vector1.b->x;
        float c1 = vector1.a->x * (vector1.a->y - vector1.b->y) + vector1.a->y * (vector1.b->x - vector1.a->x);

        float a2 = vector2.b->y - vector2.a->y;
        float b2 = vector2.a->x - vector2.b->x;
        float c2 = vector2.a->x * (vector2.a->y - vector2.b->y) + vector2.a->y * (vector2.b->x - vector2.a->x);

        // znajduję środek okręgu (punkt)
        auto o = Element::CrossingPoint(a1, b1, c1, a2, b2, c2);
        // oraz promień okręgu R równy BO i równy OF
        float r = VectorLenght(o.x, o.y, bx, by);
        //float r2 = VectorLenght(o.x, o.y, bx, by);

        // угол открытия дуги (długość łuku)
        float aBOF = abs(ConvertToDegrees(paint.back() ^ BF)) * 2;

        // pokazuję gdzie znajduje się środek okręgu
        DrawPoint(o.x, o.y);

        //glBegin(GL_LINES);
        // рисую перпендикуляр от касательной
        //glVertex2f(vector1.a->x, vector1.a->y);
        //glVertex2f(vector1.b->x, vector1.b->y);
        // рисую перпендикуляр от цетра хорды к центру окружности
        //glVertex2f(vector2.a->x, vector2.a->y);
        //glVertex2f(vector2.b->x, vector2.b->y);
        //glEnd();

        // координаты точки где начинается отчёт грагусов
        //float ArcStartX = r * cos(ConvertToRadians(0)) + o.x;
        //float ArcStartY = r * sin(ConvertToRadians(0)) + o.y;
        //Element BS(ax, ay, ArcStartX, ArcStartY);
        //float shift = ConvertToDegrees(paint.back() ^ BS) * 2; // <BOS
        //float shift = ConvertToDegrees(acos((bx - o.x) / r));

        //string title = "<BOF: " + to_string(aAB);
        //glutSetWindowTitle(title.c_str());
        //cout << "SHIFT:  " << shift << endl;

        // рисую дугу
        DrawArc(paint.back(), aABF, aBOF, r, o);
        //DrawPoint(r * cos(ConvertToRadians(0)) + p.x, r * sin(ConvertToRadians(0)) + p.y);

        // сохраняю информацию о будущей дуге
        futureArc.o = o;
        futureArc.r = r;
        futureArc.aABF = aABF;
        futureArc.aBOF = aBOF;
    }

    // rysuję ponownie aby odświeżyć
    glFlush();
}

void init2D(float r, float g, float b)
{
    // wybieram kolor tła
    glClearColor(r, g, b, 0.0f);

    // wybieram czarny kolor pęzla
    glColor3f(0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

int main(int argc, char** argv)
{
    // chowam console za pomocą WinApi
    //FreeConsole();

    // daję element testowy
    paint.emplace_back(20.f, 300.f, 260.f, 300.f);

    // инициализация GLUT Library
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // настройка размера окна (ширина, высота)
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Wielolinie w 2D (Naciśnij RightClick żeby przejść do menu)");
    // устанавливаем функцию отрисовки
    glutDisplayFunc(Display);

    // устанавливаем функцию обработки нажатий мыши
    glutMouseFunc(MouseClickEvent);
    glutPassiveMotionFunc(MouseMoveEvent);

    // buduję menu kontekstowe
    glutCreateMenu(MenuClickEvent);
    glutAddMenuEntry("Cofnąć o krok", MENU_ITEM_UNDO);
    glutAddMenuEntry("Tryb łuku", MENU_ITEM_SET_MODE);
    glutAddMenuEntry("Skończyć wielolinie", MENU_ITEM_FINISH);
    glutAddMenuEntry("Przywrócić element", MENU_ITEM_RESTORE);
    glutAddMenuEntry("Usunąć wszystko", MENU_ITEM_REMOVE_ALL);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    init2D(255.0f, 250.0f, 250.0f);
    glutDisplayFunc(Display);

    glPointSize(5);
    glutMainLoop();

    // tutaj są memory leaks, ponieważ glutMainLoop() powtarza się w nieskończoność
    // w freeGLUT mógłbym użyć glutLeaveMainLoop() (glutSetOption on linux)
    return 0;
}

/*
Program: Wielolinie w 2D (zadanie testowe)
Autor: Aleksander Czastuchin
Użyłem: GLUT 3.7 beta (The OpenGL Utility Toolkit)
Kiedy zrobiłem: robiłem Fri May 12 10:54:24 2017

1) add windows environment path for gcc and cmake
C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin
C:\Program Files\CMake\bin

2) reload terminal and check if it works
g++ -v
cmake --version

3) check if opengl is installed
cd /c/Windows/System32
ls | grep -E -i "opengl|glu"

4) compile on Windows
g++ -mwindows -o arc.exe paint.cpp main.cpp -lopengl32 -lfreeglut -lglu32 -L. -I.
g++ -std=c++17 -o arc.exe paint.cpp main.cpp -lopengl32 -lfreeglut -lglu32 -L. -I.

5) compile on Ubuntu
dpkg --search /usr/include/GL/glu.h 
dpkg --listfiles libglu1-mesa-dev:amd64 | grep lib
g++ -std=c++17 -o arc paint.cpp main.cpp -lglut -lGL -lGLU
ldd arc
libglut.so.3 => /usr/lib/x86_64-linux-gnu/libglut.so.3 (0x00007ff4dc830000)
libGL.so.1 => /usr/lib/x86_64-linux-gnu/libGL.so.1 (0x00007ff4dc5a4000)
libGLU.so.1 => /usr/lib/x86_64-linux-gnu/libGLU.so.1 (0x00007ff4dc335000)

*/