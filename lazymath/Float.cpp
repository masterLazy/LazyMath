/*****************************************************************************
 * Float.cpp
 * Floating point number
 *****************************************************************************/

#include "LazyMath.h"
using namespace lazy;

/*Float - public*/

Float::Float() {}
Float::Float(FloatType f) :value(f) {}

Float::operator FloatType() const {
	return value;
}

Float lazy::Float::operator+=(Float f) {
	return value += f.value;
}
Float lazy::Float::operator-=(Float f) {
	return value -= f.value;
}
Float lazy::Float::operator*=(Float f) {
	return value *= f.value;
}
Float lazy::Float::operator/=(Float f) {
	return value /= f.value;
}

Float lazy::Float::abs() const
{
	return ::abs(value);
}
Float lazy::Float::pow(Float f) const
{
	return ::pow(value, f);
}

bool lazy::Float::equals(const Float& f) const {
	return ::abs(value - f.value) <= EPSILON;
}

bool lazy::Float::is_zero() const {
	return abs() > EPSILON;
}
