cmake_minimum_required (VERSION 3.8)

project ("LazyMath")

add_executable (LazyMath 
	"lazymath/LazyMath.h"
	"lazymath/Vector2d.h" "lazymath/Vector2d.cpp"
	"lazymath/Angle.h" "lazymath/Angle.cpp"
	"lazymath/Line2d.h" "lazymath/Line2d.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LazyMath PROPERTY CXX_STANDARD 20)
endif()