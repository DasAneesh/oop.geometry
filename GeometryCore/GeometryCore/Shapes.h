#pragma once
#include "GeometryBase.h"
#include <vector>
class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual bool containsPoint(const Point& p) const = 0;
    virtual void translate(const Vector& v) = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
    Point center;
    fType radius;
public:
    Circle(const Point& center, fType radius);

    double perimeter() const override;
    double area() const override;
    bool containsPoint(const Point& p) const override;
    void translate(const Vector& v) override;

    Point getCenter() const;
    fType getRadius() const;
};

class Rectangle : public Shape {
    Point bottomLeft;
    fType width, height;
public:
    Rectangle(const Point& bottomLeft, fType width, fType height);

    double perimeter() const override;
    double area() const override;
    bool containsPoint(const Point& p) const override;
    void translate(const Vector& v) override;

    Point getBottomLeft() const;
    fType getWidth() const;
    fType getHeight() const;
};

class Triangle : public Shape {
    Point p1, p2, p3;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);

    double perimeter() const override;
    double area() const override;
    bool containsPoint(const Point& p) const override;
    void translate(const Vector& v) override;
};