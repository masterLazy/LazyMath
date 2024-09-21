#pragma once
/*****************************************************************************
* Angle.h
* Angle
*****************************************************************************/

namespace lazy {
	//Auxiliary classes
	class Deg {
	public:
		Float d;
		Deg(Float degree);
		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Deg& deg);
	};

	class Rad {
	public:
		Float r;
		Rad(Float radian);
		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Rad& rad);
	};

	class Angle {
	private:
		Float fac; //This angle = fac * PI
		Angle(Float fac);
	public:

		Angle();
		Angle(Deg deg);
		Angle(Rad rad);

		Float deg() const;
		Float rad() const;

		//Simplify the angle into [0, 2 * pi]
		void simplify();
		//Absolute value
		Angle abs() const;

		Angle operator-() const;
		Angle operator+(const Angle& angle) const;
		Angle operator-(const Angle& angle) const;
		Float operator/(const Angle& angle) const;
		Angle operator*(const Float f) const;
		Angle operator/(const Float f) const;
		friend Angle operator*(const Float f, const Angle& angle);

		Angle operator+=(const Angle& angle);
		Angle operator-=(const Angle& angle);
		Angle operator*=(const Float f);
		Angle operator/=(const Float f);

		//Comparation
		bool operator==(const Angle& angle) const;
		bool operator!=(const Angle& angle) const;
		bool operator>(const Angle& angle) const;
		bool operator<(const Angle& angle) const;
		bool operator>=(const Angle& angle) const;
		bool operator<=(const Angle& angle) const;

		//ostream
		friend std::ostream& operator<<(std::ostream&, const Angle&);
	};

	inline Float sin(Angle angle) {
		return ::sin(angle.rad());
	}
	inline Float cos(Angle angle) {
		return ::cos(angle.rad());
	}
	inline Float tan(Angle angle) {
		return ::tan(angle.rad());
	}
	inline Angle asin(Float f) {
		return Rad(::asin(f));
	}
	inline Angle acos(Float f) {
		return Rad(::acos(f));
	}
	inline Angle atan(Float f) {
		return Rad(::atan(f));
	}
	inline Angle atan2(Float x, Float y) {
		return Rad(::atan2(x, y));
	}
}