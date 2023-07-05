#include "./Fixed.hpp"

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->fixed_point = fix.GetRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::GetRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
} 

void Fixed::SetRawBits(int const raw)
{
	this->fixed_point = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.GetRawBits() << std::endl;
	return (os);
}
