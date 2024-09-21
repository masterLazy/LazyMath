#pragma once
/*****************************************************************************
 * Float.h
 * Floating point number
 *****************************************************************************/

namespace lazy {
	typedef float FloatType;

	const FloatType E = M_E;
	const FloatType PI = M_PI;
	const FloatType EPSILON = std::numeric_limits<FloatType>::epsilon();

	class Float {
	private:
		FloatType value;
	public:
		Float();
		Float(FloatType);
		operator FloatType() const;

		Float abs() const;
		Float pow(Float) const;

		bool equals(const Float&) const;
		bool is_zero() const;

		Float operator+=(Float);
		Float operator-=(Float);
		Float operator*=(Float);
		Float operator/=(Float);

		friend std::ostream& operator<<(std::ostream&, const Float&);
	};
}