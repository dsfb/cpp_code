#ifndef PAINT_HEADER
#define PAINT_HEADER

#include <cmath>
#include <iostream>
#include <list>
#include <memory>

using std::atan2;
using std::cout;
using std::endl;
using std::list;
using std::shared_ptr;

#define PI 3.14159265f

// Długość wektora (moduł) (длина вектора по модулю)
float VectorLenght(float x1, float y1, float x2, float y2);

// Преобразовать радианы в градусы
float inline ConvertToDegrees(float radians)
{
    return (radians * 180.0f) / PI;
}

// Преобразовать градусы в радианы
float inline ConvertToRadians(float degrees)
{
    return (degrees * PI) / 180.0f;
}

// Prosty punkt i wrapper dla niego
struct Point {
    float x, y;
};
using PointWrapper = shared_ptr<Point>;

// Tryb działania programu
enum class Mode { Line,
    Arc };
// Typ elementu
enum class ElementType { Line,
    Arc };

// Informacia dla tworzenia przyszłego łuku
struct ArcInfo {
    // Promień okręgu
    float r;
    // Środek okręgu (punkt)
    Point o;
    // Kąt pomiędzy AB & BF, gdzie AB - ostatnia stworzona linia
    float aABF;
    // Kąt BO & OF, gdzie BO=OF=r oraz O - środek okręgu
    float aBOF;
};

// Część okręgu (circle quadrant)
enum class CirclePart {
    BetweenZeroAndOne = 1,
    BetweenOneAndTwo,
    BetweenTwoAndThree,
    BetweenThreeAndFour

};

struct Element {
public:
    Element();
    Element(float x1, float y1, float x2, float y2);
    Element(const PointWrapper start, float length = 1000);
    Element(const Element& elem);

    // Początkowy punkt elementu
    PointWrapper a;
    // Końcowy punkt elementu
    PointWrapper b;
    // Bieżący typ elementu wielolinii
    ElementType type;
    // Informacja dla tworzenia łuku
    ArcInfo arcInfo;

    // Długość wektora (moduł) |a|
    float GetLenght() const;

    // Векторное произведение (Iloczyn wektorowy)
    float operator*(const Element& elem);

    // Угол между векторами (функция возвращает значение в радианах)
    float operator^(const Element& elem);

    // Определитеть 2го порядка матрицы
    /*float Determinant2(float a11, float a12, float a21, float a22)
	{
		return a11*a22 - a12*a21;
	}*/

    // Функция находит точку пересечания двух векторов
    static Point CrossingPoint(float a1, float b1, float c1, float a2, float b2, float c2);

    // Поворот относительно начала отрезка
    void Rotate(float angle);

    // Угол наклона прямой относительно оси X в градусах
    float inline GetAngleX() const
    {
        return ConvertToDegrees(atan2(b->y - a->y, b->x - a->x));
    }

    // Показывает в какую сторону наклонена прямая
    bool inline IsLeftSide()
    {
        auto var = GetAngleX();
        if (var > 0 && var <= 90)
            return false;
        else if (var < 0 && abs(var) > 90)
            return false;
        else
            return true;
    }

    ~Element();
};

using Elements = list<Element>;
class Paint final : public Elements {
public:
    Paint();
    // Jeśli to jest koniec krzywej
    bool IsFinish;
    // Bierzący tryb działania programu
    Mode CurrentMode;

    bool inline IsFirstElement() const
    {
        return (size() == 1 && back().b == nullptr) ? true : false;
    }

    // Cofnąć o krok
    void Back();

    // Przywrócić element
    void Restore();

    void inline ClearHistory()
    {
        deleted.clear();
    }

    void inline RemoveAll()
    {
        clear(); // call ~Element()
        ClearHistory();
    }

    // Nie przetestowałem bo glutMainLoop() jest niekończąca się
    // i to jest wada tej bibloiteki
    ~Paint();

private:
    // Usunięte elementy chowam tutaj
    Elements deleted;
};
#endif