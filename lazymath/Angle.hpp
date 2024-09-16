#pragma once
/*****************************************************************************
* Angle.hpp
* Angle
*****************************************************************************/

namespace lazy {
	//Auxiliary classes
	class Deg {
	public:
		Float d;
		Deg(Float degree) :d(degree) {}
		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Deg& deg) {
			return os << deg.d << " deg";
		}
	};

	class Rad {
	public:
		Float r;
		Rad(Float radian) :r(radian) {}
		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Rad& rad) {
			return os << rad.r << " rad";
		}
	};

	class Angle {
	private:
		Float fac; //This angle = fac * PI
		Angle(Float _fac) :fac(_fac) {}
	public:

		Angle() :fac(0) {}
		Angle(Deg deg) :fac(deg.d / 180) {}
		Angle(Rad rad) :fac(rad.r / PI) {}

		Float deg() const {
			return fac * 180;
		}
		Float rad() const {
			return fac * PI;
		}

		//Simplify the angle into [0, 2*PI]
		void simplify() {
			while (fac > 2)fac -= 2;
			while (fac < 0)fac += 2;
		}

		Angle operator-() const {
			return { fac + 1 };
		}
		Angle operator+(const Angle& angle) const {
			return { fac + angle.fac };
		}
		Angle operator-(const Angle& angle) const {
			return { fac - angle.fac };
		}
		Float operator/(const Angle& angle) const {
			return { fac / angle.fac };
		}
		Angle operator*(const Float f) const {
			return { fac * f };
		}
		Angle operator/(const Float f) const {
			return { fac / f };
		}
		friend Angle operator*(const Float f, const Angle& angle) {
			return { f * angle.fac };
		}

		Angle operator+=(const Angle& angle) {
			fac += angle.fac;
			return *this;
		}
		Angle operator-=(const Angle& angle) {
			fac -= angle.fac;
			return *this;
		}
		Angle operator*=(const Float f) {
			fac *= f;
		}
		Angle operator/=(const Float f) {
			fac /= f;
		}

		//Comparation
		bool operator==(const Angle& angle) const {
			return fac == angle.fac;
		}
		bool operator!=(const Angle& angle) const {
			return fac != angle.fac;
		}
		bool operator>(const Angle& angle) const {
			return fac > angle.fac;
		}
		bool operator<(const Angle& angle) const {
			return fac < angle.fac;
		}
		bool operator>=(const Angle& angle) const {
			return fac >= angle.fac;
		}
		bool operator<=(const Angle& angle) const {
			return fac <= angle.fac;
		}

		//ostream
		friend std::ostream& operator<<(std::ostream& os, const Angle& angle) {
			return os << angle.deg() << " deg";
		}
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