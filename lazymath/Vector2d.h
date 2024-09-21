#pragma once
/*****************************************************************************
* Vector2d.h
* Vector in 2D space
*****************************************************************************/

namespace lazy {
	//Vector in 2D space
	class Vector2d {
	public:
		Float x, y;

		Vector2d();
		Vector2d(Float x, Float y);
		Vector2d(const Vector2d& from_point, const Vector2d& to_point);

		//Norm of the vector
		Float norm() const;
		//Dot product
		Float dot(const Vector2d& v) const;
		//Norm of cross product
		Float cross(const Vector2d& v) const;
		//Angle with positive-x axis
		Angle angle() const;
		//Angle between two vectors (this vector -> v)
		Angle angle_with(const Vector2d& v) const;

		void operator-();
		Vector2d operator+(const Vector2d& v) const;
		Vector2d operator-(const Vector2d& v) const;

		Vector2d operator+=(const Vector2d& v);
		Vector2d operator-=(const Vector2d& v);

		//Comparation
		bool operator==(const Vector2d& v) const;
		bool operator!=(const Vector2d& v) const;

		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector);
	};
	//Point in 2D space
	typedef Vector2d Point2d;
}