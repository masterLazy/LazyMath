#pragma once
/*****************************************************************************
* Vector2d.hpp
* Vector in 2D space
*****************************************************************************/

namespace lazy {
	class Vector2d {
	public:
		Float x, y;

		Vector2d() :x(0), y(0) {}
		Vector2d(Float _x, Float _y) :x(_x), y(_y) {}
		Vector2d(const Vector2d& from_point, const Vector2d& to_point)
			:x(to_point.x - from_point.x), y(to_point.y - from_point.y) {}

		//Dot product
		Float dot(const Vector2d& v) const {
			return x * v.x + y * v.y;
		}
		//Mod of cross product
		Float cross(const Vector2d& v) const {
			return x * v.y - y * v.x;
		}

		//Invert
		void operator-() {
			x = -x, y = -y;
		}
		Vector2d operator+(const Vector2d& v) const {
			return Vector2d(x + v.x, y + v.y);
		}
		Vector2d operator-(const Vector2d& v) const {
			return Vector2d(x - v.x, y - v.y);
		}

		Vector2d operator+=(const Vector2d& v) {
			x += v.x, y += v.y;
			return *this;
		}
		Vector2d operator-=(const Vector2d& v) {
			x -= v.x, y -= v.y;
			return *this;
		}

		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Vector2d& pt) {
			return os << "[" << pt.x << ", " << pt.y << "]";
		}
	};
	typedef Vector2d Point2d;
}