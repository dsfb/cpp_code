#include "paint.h"
#include <cmath>

//using std::atan2;
//using std::sin;
using namespace std;

float VectorLenght(float x1, float y1, float x2, float y2)
{
    // wektor A(ax, ay)
    float ax = x2 - x1;
    float ay = y2 - y1;
    return sqrt(ax * ax + ay * ay);
}

Element::Element()
{
    type = ElementType::Line;
    a = PointWrapper(new Point);
    b = PointWrapper(new Point);
}

Element::Element(float x1, float y1, float x2, float y2)
{
    type = ElementType::Line;
    a = PointWrapper(new Point);
    b = PointWrapper(new Point);
    a->x = x1;
    a->y = y1;
    b->x = x2;
    b->y = y2;
}

Element::Element(const PointWrapper start, float length)
{
    a = PointWrapper(new Point);
    b = PointWrapper(new Point);
    *a = *start;
    b->x = a->x + length;
    b->y = a->y;
    type = ElementType::Line;
}

Element::Element(const Element& elem)
{
    cout << "Element(const Element& elem)" << endl;
    a = PointWrapper(new Point);
    b = PointWrapper(new Point);
    a->x = elem.a->x;
    a->y = elem.a->y;
    b->x = elem.b->x;
    b->y = elem.b->y;
    type = elem.type;
    arcInfo = elem.arcInfo;
}

float Element::GetLenght() const
{
    // wektor A(ax, ay)
    float ax = b->x - a->x;
    float ay = b->y - a->y;
    return sqrt(ax * ax + ay * ay);
}

float Element::operator*(const Element& elem)
{
    // вектор A(ax, ay)
    float ax = b->x - a->x;
    float ay = b->y - a->y;

    // вектор B(bx, by)
    float bx = elem.b->x - elem.a->x;
    float by = elem.b->y - elem.a->y;

    return (ax * by) - (ay * bx);
}

float Element::operator^(const Element& elem)
{
    // wektor A(ax, ay)
    float ax = b->x - a->x;
    float ay = b->y - a->y;

    // wektor B(bx, by)
    float bx = elem.b->x - elem.a->x;
    float by = elem.b->y - elem.a->y;

    return atan2(ax * by - ay * bx, ax * bx + ay * by); // <AB
}

Point Element::CrossingPoint(float a1, float b1, float c1, float a2, float b2, float c2)
{
    Point pt;
    float d = a1 * b2 - b1 * a2;
    float dx = (-c1 * b2 + b1 * c2);
    float dy = (-a1 * c2 + c1 * a2);
    pt.x = dx / d;
    pt.y = dy / d;
    return pt;
}

void Element::Rotate(float angle)
{
    float vx = b->x - a->x;
    float vy = b->y - a->y;
    float nx = cos(angle) * vx - sin(angle) * vy + a->x;
    float ny = sin(angle) * vx - cos(angle) * vy + a->y;
    b->x = nx;
    b->y = ny;
}

Element::~Element()
{
    cout << "~Element()" << endl;
    a = nullptr;
    b = nullptr;
}

Paint::Paint()
{
    IsFinish = false;
    CurrentMode = Mode::Line;
}

void Paint::Back()
{
    if (empty() /*|| IsFirstElement()*/)
        return;
    // destination (dest_place, source, source_place)
    deleted.splice(deleted.end(), *this, --end());
}

void Paint::Restore()
{
    if (deleted.empty())
        return;
    splice(end(), deleted, --deleted.end());
}

Paint::~Paint()
{
    clear();
    deleted.clear();
}