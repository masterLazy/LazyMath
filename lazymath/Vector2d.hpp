#pragma once
/*****************************************************************************
* Vector2d.hpp
* Vector in 2D space
*****************************************************************************/

namespace lazy {
	//Vector in 2D space
	class Vector2d {
	public:
		Float x, y;

		Vector2d() :x(0), y(0) {}
		Vector2d(Float x, Float y) :x(x), y(y) {}
		Vector2d(const Vector2d& from_point, const Vector2d& to_point)
			:x(to_point.x - from_point.x), y(to_point.y - from_point.y) {}

		//Norm of the vector
		Float norm() const {
			return sqrt(x * x + y * y);
		}
		//Dot product
		Float dot(const Vector2d& v) const {
			return x * v.x + y * v.y;
		}
		//Norm of cross product
		Float cross(const Vector2d& v) const {
			return x * v.y - y * v.x;
		}
		//Angle with positive-x axis
		Angle angle() const {
			return atan2(y, x);
		}
		//Angle between two vectors (this vector -> v)
		Angle angle_with(const Vector2d& v) const {
			return v.angle() - angle();
		}

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

		//Comparation
		bool operator==(const Vector2d& v) const {
			return equal(x, v.x) && equal(y, v.y);
		}
		bool operator!=(const Vector2d& v) const {
			return !(*this == v);
		}

		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
			return os << "[" << vector.x << ", " << vector.y << "]";
		}
	};
	//Point in 2D space
	typedef Vector2d Point2d;
}