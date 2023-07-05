#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed_point;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();
	Fixed &operator=(const Fixed&);
	int GetRawBits(void) const;
	void SetRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);
#endif