#include "./Point.hpp"

static float GetAreaofTriangle(Point a, Point b)
{	
	return (0.5 * (a.GetX().toFloat() * b.GetY().toFloat() - a.GetY().toFloat() * b.GetX().toFloat()) \
		* (a.GetX().toFloat() * b.GetY().toFloat() - a.GetY().toFloat() * b.GetX().toFloat()));
}

static bool area(Fixed s)
{
	if (s.toFloat() > -1e-6 && s.toFloat() < 1e-5)
		return (false);
	return (true);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed s1(GetAreaofTriangle(a - point, b - point));
	Fixed s2(GetAreaofTriangle(a - point, c - point));
	Fixed s3(GetAreaofTriangle(b - point, c - point));
	Fixed s(GetAreaofTriangle(a - b, a - c));

	if (!area(s1) || !area(s2) || !area(s3))
		return (false);
	if (s1 + s2 + s3 <= s)
		return (true);
	return (false);
}