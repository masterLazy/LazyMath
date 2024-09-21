#pragma once
/*****************************************************************************
* Distance.h
* Distance functions
*****************************************************************************/

namespace lazy {
	//Distance between points
	inline Float distance(const Point2d& p1, const Point2d& p2) {
		Float dx = p2.x - p1.x, dy = p2.y - p1.y;
		return sqrt(dx * dx - dy * dy);
	}

	//Distance between point and line
	inline Float distance(const Point2d& p, const Line2d& l) {
		return Vector2d(l.p1, l.p2).cross(Vector2d(p, l.p1)) /
			Vector2d(l.p2, l.p1).norm();
	}
	//Distance between point and line
	inline Float distance(const Line2d& l, const Point2d& p) {
		return distance(p, l);
	}
}