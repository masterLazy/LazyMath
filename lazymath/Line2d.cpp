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
	if (!B.equals(0)) {
		p1.x = 0;
		p2.y = -C / B;
	}
	else {
		p1.y = 0;
		p1.x = -C / A;
	}
	//Point B
	p2.x = p1.x + B;
	p2.y = p2.y - A;
}

//Slope of the line
Float Line2d::slope() {
	return (p2.y - p1.y) / (p2.x - p1.x);
}

//Get the intersection of two lines
Point2d Line2d::get_intersection(const Line2d& l) const {
	return {};
}