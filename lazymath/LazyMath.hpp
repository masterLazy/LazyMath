#pragma once
/*****************************************************************************
 * LazyMath.hpp
 * The main header of lazymath.
 *****************************************************************************/

#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>

namespace lazy {
	typedef float Float;

	const Float E = M_E;
	const Float PI = M_PI;
	const Float EPSILON = std::numeric_limits<Float>::epsilon();

	bool equal(Float a, Float b) {
		return abs(a - b) <= EPSILON;
	}
}

//Geometry
#include "Angle.hpp"
#include "Vector2d.hpp"
#include "Line2d.hpp"
#include "Distance.hpp"