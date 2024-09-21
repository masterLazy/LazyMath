#pragma once
/*****************************************************************************
* Line2d.cpp
* Line in 2D space
*****************************************************************************/

#include "LazyMath.h"
using namespace lazy;

/*Line2d - public*/

Line2d::Line2d() :p1(0, 0), p2(0, 0) {}
Line2d::Line2d(Point2d p1, Point2d p2) :p1(p1), p2(p2) {}

Line2d::Line2d(Float A, Float B, Float C) {
	//Point A
	if (A.equals(0)) {
		p1 = { 0, -C / B };
		p2 = { 1, -C / B };
	}
	else if (B.equals(0)) {
		p1 = { -C / A, 0 };
		p2 = { -C / A, 1 };
	}
	else {
		p1 = { 0, -C / B };
		p2 = { 1, (-C - A) / B };
	}
}

bool lazy::Line2d::equals(const Line2d& l) const {
	return is_paral(l) && is_pass(l.p1);
}

bool lazy::Line2d::is_pass(const Point2d& p) const {
	return (p - p1).cross((p2 - p1)).is_zero();
}
bool lazy::Line2d::is_paral(const Line2d& l) const {
	return (p2 - p1).cross((l.p2 - l.p1)).is_zero();
}
bool lazy::Line2d::is_cross(const Line2d& l) const {
	return !is_paral(l);
}

Float Line2d::get_slope() {
	return (p2.y - p1.y) / (p2.x - p1.x);
}
Point2d Line2d::get_cross_point(const Line2d& l) const {
	Float s1 = (p2 - p1).cross((l.p1 - p1));
	Float s2 = (p2 - p1).cross((l.p2 - p1));
	return Point2d{ l.p1.x * s2 - l.p2.x * s1,l.p1.y * s2 - l.p2.y * s1 } / (s2 - s1);
}
Point2d lazy::Line2d::get_proj(const Point2d& p) const {
	Float k = (p2 - p1).dot(p - p1) / (p2 - p1).norm().pow(2);
	return p1 + (p2 - p1) * k;
}
