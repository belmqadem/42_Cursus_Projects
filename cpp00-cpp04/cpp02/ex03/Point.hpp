#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point( const float, const float );
		Point ( const Point & );
		Point &operator = ( const Point & );
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area(Point const p1, Point const p2, Point const p3);


#endif