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
	};

	class Rad {
	public:
		Float r;
		Rad(Float radian) :r(radian) {}
	};

	class Angle {
	private:
		Float fac; //This angle = fac * PI
		Angle(Float _fac) :fac(_fac) {}
	public:

		Angle() {}
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
	};
}