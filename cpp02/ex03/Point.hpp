#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		Point operator-(const Point& b) const;
		~Point();
		Fixed GetX() const;
		Fixed GetY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif