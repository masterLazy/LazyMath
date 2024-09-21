#pragma once
/*****************************************************************************
* Line2d.h
* Line in 2D space
*****************************************************************************/

namespace lazy {
	//Line in 2D space
	class Line2d {
	public:
		Point2d p1, p2;

		Line2d();
		Line2d(Point2d p1, Point2d p2);
        //l: Ax + By + C = 0
		Line2d(Float A, Float B, Float C);

        //Slope of the line
		Float slope();

        //Get the intersection of two lines
		Point2d get_intersection(const Line2d& l) const;
	};
}