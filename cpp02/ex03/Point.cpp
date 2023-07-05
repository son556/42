#include "./Point.hpp"

Point::Point() : x(), y()
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		const_cast<Fixed&>(x) = obj.x;
		const_cast<Fixed&>(y) = obj.y;
	}
	return (*this);
}

Point Point::operator-(const Point& b) const
{
	Point temp;

	const_cast<Fixed&>(temp.x) = Fixed(this->GetX().toFloat() - b.GetX().toFloat());
	const_cast<Fixed&>(temp.y) = Fixed(this->GetY().toFloat() - b.GetY().toFloat());
	return (temp);
}

Fixed Point::GetX() const
{
	return (x);
}

Fixed Point::GetY() const
{
	return (y);
}