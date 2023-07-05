#include "./Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int point)
{
	std::cout << "Int constructor called" << std::endl;
	SetRawBits(point);
}

Fixed::Fixed(const float point)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(point * (256));

}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->fixed_point = fix.GetRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

int Fixed::GetRawBits() const
{
	return (fixed_point);
}

void Fixed::SetRawBits(int const raw)
{
	fixed_point = (raw << bits);
}

int Fixed::toInt(void) const
{
	return (GetRawBits() >> bits);
}

float Fixed::toFloat(void) const
{
	return ((float)GetRawBits() / 256);
}
