#include "./Point.hpp"

int main(void)
{
	Point a(2, 9);
	Point b(5, 5);
	Point c(0, 5);
	Point p(3, 7);

	if (bsp(a, b, c, p))
		std::cout << "point in triangle" << std::endl;
	else
		std::cout << "point out triangle" << std::endl;
	return (0);
}