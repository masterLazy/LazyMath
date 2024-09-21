#pragma once
/*****************************************************************************
* Line2d.h
* Line in 2D space
*****************************************************************************/

namespace lazy {
	// Line in 2D space
	class Line2d {
	public:
		Point2d p1, p2;

		Line2d();
		Line2d(Point2d p1, Point2d p2);
        // l: Ax + By + C = 0
		Line2d(Float A, Float B, Float C);

		// If lines overlap
		bool equals(const Line2d&) const;

		// If the line passes the point
		bool is_pass(const Point2d&) const;
		// If the lines are parallel (or overlap)
		bool is_paral(const Line2d&) const;
		// If lines cross
		bool is_cross(const Line2d&) const;

		// Get slope of the line
		Float get_slope();
        // Get cross point of two lines
		Point2d get_cross_point(const Line2d&) const;
		// Get point's projection on the line
		Point2d get_proj(const Point2d&) const;
	};

	// Cross point of two lines
	inline Point2d get_cross_point(const Line2d& l1, const Line2d& l2) {
		return l1.get_cross_point(l2);
	}
}