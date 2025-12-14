#include "GeometryBase.h"


Vector::Vector(fType dx, fType dy) : dx(dx), dy(dy) {}

Vector Vector::operator+(const Vector& other) const {
	return Vector(this->dx + other.dx, this->dy + other.dy);
}

Vector Vector::operator-(const Vector& other) const {
	return Vector(this->dx - other.dx, this->dy - other.dy);
}

Vector Vector::operator*(fType scalar) const {
	return Vector(this->dx * scalar, this->dy * scalar);
}

Vector Vector::operator/(fType scalar) const {
	if(std::abs(scalar) < Epsilon)
		return Vector(this->dx / scalar, this->dy / scalar);
	throw std::invalid_argument("Vector cannot divide by 0.");
}

bool Vector::operator==(const Vector& other) const {
	return Epsilon > std::abs(this->dx - other.dx) && Epsilon > std::abs(this->dy - other.dy);
}
bool Vector::operator!=(const Vector& other) const {
	return Epsilon < std::abs(this->dx - other.dx) || Epsilon < std::abs(this->dy - other.dy);

	// return !(*this == other)
}
fType Vector::length() const {
	return std::sqrt(this->dx * this->dx + this->dy * this->dy);
}

Vector Vector::normalized() const {
	fType len = length();
	if (std::abs(len) < Epsilon) { return Vector(0, 0); }
	return Vector(this->dx / len, this->dy / len);

}

fType Vector::dotProduct(const Vector& other) const {
	return this->dx * other.dx + this->dy * other.dy;
}

fType Vector::crossProduct(const Vector& other) const {
	return this->dx * other.dy - this->dy * other.dx;
}

fType Vector::getX() const {
	return this->dx;
}

fType Vector::getY() const {
	return this->dy;
}

Point::Point(fType x, fType y) : x(x), y(y) {}

Point::Point(const Vector& v) : x(v.dx), y(v.dy) {}

Point Point::operator+(const Vector& v) const {
	return Point(x + v.dx, y + v.dy);
}

Point Point::operator-(const Vector& v) const {
	return Point(x - v.dx, y - v.dy);
}

Vector Point::operator-(const Point& other) const {
	return Vector(x - other.x, y - other.y);
}

bool Point::operator==(const Point& other) const {
	return std::abs(x - other.x) < Epsilon && std::abs(y - other.y) < Epsilon;
}

bool Point::operator!=(const Point& other) const {
	return !(*this == other);
}

fType Point::distanceTo(const Point& other) const {
	return (*this - other).length();
}

Point Point::rotate(const Point& center, fType angle) const {
	Vector v = *this - center;

	fType cosA = std::cos(angle);
	fType sinA = std::sin(angle);

	fType newX = v.dx * cosA - v.dy * sinA;
	fType newY = v.dx * sinA + v.dy * cosA;

	return center + Vector(newX, newY);
}


Point Point::translate(const Vector& v) const {
	return *this + v;
}

fType Point::getX() const { return x; }
fType Point::getY() const { return y; }