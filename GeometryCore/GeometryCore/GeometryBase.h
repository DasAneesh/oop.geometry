#pragma once
#include <cmath>
#include <iostream>

using fType = double;
const fType Epsilon = 1e-6;

class Point;

class Vector {
public:

	fType dx, dy;

	Vector(fType dx = 0, fType dy = 0);

	//operators
	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator*(fType scalar) const;
	Vector operator/(fType scalar) const;
	bool operator==(const Vector& other) const;
	bool operator!=(const Vector& other) const;

	//methods
	fType length() const;
	Vector normalized() const;
	fType dotProduct(const Vector& other) const;
	fType crossProduct(const Vector& other) const;

	fType getX() const;
	fType getY() const;

};

class Point {
public:
	fType x, y;

	Point(fType x = 0, fType y = 0);
	Point(const Vector& v);

	//operators
	Point operator+(const Vector& v) const;
	Point operator-(const Vector& v) const;
	Vector operator-(const Point& other) const;
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	//methods
	fType distanceTo(const Point& other) const;
	Point rotate(const Point& center, fType angle) const;
	Point translate(const Vector& v) const;

	fType getX() const;
	fType getY() const;
};