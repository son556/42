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
	Fixed(const Fixed&);
	~Fixed();
	Fixed &operator=(const Fixed&);
	int GetRawBits(void) const;
	void SetRawBits(int const raw);
};

#endif