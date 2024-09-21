/*****************************************************************************
* Vector2d.cpp
* Vector in 2D space
*****************************************************************************/

#include "LazyMath.h"
using namespace lazy;

/*Vector2d - public*/

Vector2d::Vector2d() :x(0), y(0) {}
Vector2d::Vector2d(Float x, Float y) :x(x), y(y) {}
Vector2d::Vector2d(const Vector2d& p1, const Vector2d& p2) {
	*this = p2 - p1;
}

Float Vector2d::norm() const {
	return sqrt(x * x + y * y);
}
Float Vector2d::dot(const Vector2d& v) const {
	return x * v.x + y * v.y;
}
Float Vector2d::cross(const Vector2d& v) const {
	return x * v.y - y * v.x;
}
Angle Vector2d::angle() const {
	return atan2(y, x);
}
Angle Vector2d::angle_with(const Vector2d& v) const {
	return v.angle() - angle();
}

void Vector2d::operator-() {
	x = -x, y = -y;
}
Vector2d Vector2d::operator+(const Vector2d& v) const {
	return { x + v.x, y + v.y };
}
Vector2d Vector2d::operator-(const Vector2d& v) const {
	return { x - v.x, y - v.y };
}
Vector2d Vector2d::operator*(Float f) const {
	return { x * f, y * f };
}
Vector2d Vector2d::operator/(Float f) const {
	return { x / f, y / f };
}

Vector2d Vector2d::operator+=(const Vector2d& v) {
	x += v.x, y += v.y;
	return *this;
}
Vector2d Vector2d::operator-=(const Vector2d& v) {
	x -= v.x, y -= v.y;
	return *this;
}

bool Vector2d::operator==(const Vector2d& v) const {
	return x.equals(v.x) && y.equals(v.y);
}
bool Vector2d::operator!=(const Vector2d& v) const {
	return !(*this == v);
}

/*Vector2d - friend*/

std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
	return os << "[" << vector.x << ", " << vector.y << "]";
}

Vector2d operator*(Float f, const Vector2d& v) {
	return v * f;
}