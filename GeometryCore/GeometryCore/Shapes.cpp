#include "Shapes.h"
 
#include <cmath>
#include <stdexcept>
#include <algorithm>

const double PI = 3.141592653589793;

Circle::Circle(const Point& center, fType radius) : center(center), radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Circle radius must be positive");
    }
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

double Circle::area() const {
    return PI * radius * radius;
}

bool Circle::containsPoint(const Point& p) const {
    return center.distanceTo(p) <= radius + Epsilon;
}

void Circle::translate(const Vector& v) {
    center = center.translate(v);
}

Point Circle::getCenter() const { return center; }
fType Circle::getRadius() const { return radius; }


Rectangle::Rectangle(const Point& bottomLeft, fType width, fType height)
    : bottomLeft(bottomLeft), width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Rectangle widht and lenght must be positive");
    }
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

double Rectangle::area() const {
    return width * height;
}

bool Rectangle::containsPoint(const Point& p) const {

    bool xInside = p.x >= bottomLeft.x - Epsilon && p.x <= bottomLeft.x + width + Epsilon;
    bool yInside = p.y >= bottomLeft.y - Epsilon && p.y <= bottomLeft.y + height + Epsilon;

    return xInside && yInside;
}

void Rectangle::translate(const Vector& v) {
    bottomLeft = bottomLeft.translate(v);
}

Point Rectangle::getBottomLeft() const { return bottomLeft; }
fType Rectangle::getWidth() const { return width; }
fType Rectangle::getHeight() const { return height; }

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : p1(p1), p2(p2), p3(p3) {

    Vector v1 = p2 - p1;
    Vector v2 = p3 - p1;

    if (std::abs(v1.crossProduct(v2)) < Epsilon) {
        throw std::invalid_argument("Triangle tree points are on one line");
    }
}

double Triangle::perimeter() const {
    return p1.distanceTo(p2) + p2.distanceTo(p3) + p3.distanceTo(p1);
}

double Triangle::area() const {
    Vector v1 = p2 - p1;
    Vector v2 = p3 - p1;
    return 0.5 * std::abs(v1.crossProduct(v2));
}

bool Triangle::containsPoint(const Point& p) const {

    fType val1 = (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
    fType val2 = (p3.x - p2.x) * (p.y - p2.y) - (p3.y - p2.y) * (p.x - p2.x);
    fType val3 = (p1.x - p3.x) * (p.y - p3.y) - (p1.y - p3.y) * (p.x - p3.x);

  
    bool has_neg = (val1 < -Epsilon) || (val2 < -Epsilon) || (val3 < -Epsilon);
    bool has_pos = (val1 > Epsilon) || (val2 > Epsilon) || (val3 > Epsilon);
    return !(has_neg && has_pos);
}

void Triangle::translate(const Vector& v) {
    p1 = p1.translate(v);
    p2 = p2.translate(v);
    p3 = p3.translate(v);
}