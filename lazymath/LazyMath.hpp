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
	const Float PI = M_PI;
}

//Geometry
#include "Angle.hpp"
#include "Vector2d.hpp"