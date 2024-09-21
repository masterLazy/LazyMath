/*****************************************************************************
* Angle.cpp
* Angle
*****************************************************************************/

#include "LazyMath.h"
using namespace lazy;

/*Deg - public*/

Deg::Deg(Float degree) :d(degree) {}

/*Deg - public friend*/

std::ostream& operator<<(std::ostream& os, const Deg& deg) {
	return os << deg.d << " deg";
}

/*Rad - public*/

Rad::Rad(Float radian) :r(radian) {}

/*Rad - public friend*/

std::ostream& operator<<(std::ostream& os, const Rad& rad) {
	return os << rad.r << " rad";
}

/*Angle - private*/

Angle::Angle(Float fac) :fac(fac) {}

/*Angle - public*/

Angle::Angle() :fac(0) {}
Angle::Angle(Deg deg) :fac(deg.d / 180) {}
Angle::Angle(Rad rad) :fac(rad.r / PI) {}

Float Angle::deg() const {
	return fac * 180;
}
Float Angle::rad() const {
	return fac * PI;
}

void Angle::simplify() {
	while (fac > 2)fac -= 2;
	while (fac < 0)fac += 2;
}
Angle Angle::abs() const {
	return { ::abs(fac) };
}

Angle Angle::operator-() const {
	return { fac + 1 };
}
Angle Angle::operator+(const Angle& angle) const {
	return { fac + angle.fac };
}
Angle Angle::operator-(const Angle& angle) const {
	return { fac - angle.fac };
}
Float Angle::operator/(const Angle& angle) const {
	return { fac / angle.fac };
}
Angle Angle::operator*(const Float f) const {
	return { fac * f };
}
Angle Angle::operator/(const Float f) const {
	return { fac / f };
}

Angle Angle::operator+=(const Angle& angle) {
	fac += angle.fac;
	return *this;
}
Angle Angle::operator-=(const Angle& angle) {
	fac -= angle.fac;
	return *this;
}
Angle Angle::operator*=(const Float f) {
	fac *= f;
	return *this;
}
Angle Angle::operator/=(const Float f) {
	fac /= f;
	return *this;
}

bool Angle::operator==(const Angle& angle) const {
	return equal(fac, angle.fac);
}
bool Angle::operator!=(const Angle& angle) const {
	return !(*this == angle);
}
bool Angle::operator>(const Angle& angle) const {
	return fac > angle.fac;
}
bool Angle::operator<(const Angle& angle) const {
	return fac < angle.fac;
}
bool Angle::operator>=(const Angle& angle) const {
	return !(*this < angle);
}
bool Angle::operator<=(const Angle& angle) const {
	return !(*this > angle);
}

/*Angle - public friend*/

Angle operator*(const Float f, const Angle& angle) {
	return angle * f;
}
std::ostream& operator<<(std::ostream& os, const Angle& angle) {
	return os << angle.deg() << " deg";
}