#include "./Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
}

Fixed::Fixed(const int point)
{
	SetRawBits(point);
}

Fixed::Fixed(const float point)
{
	fixed_point = roundf(point * (256));
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& fix)
{
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
	fixed_point = (raw * 256);
}

int Fixed::toInt(void) const
{
	return (GetRawBits() / 256);
}

float Fixed::toFloat(void) const
{
	return ((float)GetRawBits() / (256));
}

bool Fixed::operator>(const Fixed& fix) const
{
	if (this->GetRawBits() > fix.GetRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& fix) const
{
	if (this->GetRawBits() < fix.GetRawBits())
		return (true);
	return(false);
}

bool Fixed::operator>=(const Fixed& fix) const
{
	if (this->GetRawBits() >= fix.GetRawBits())
		return (true);
	return(false);
}

bool Fixed::operator<=(const Fixed& fix) const
{
	if (this->GetRawBits() <= fix.GetRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& fix) const
{
	if (this->GetRawBits() == fix.GetRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& fix) const
{
	if (this->GetRawBits() != fix.GetRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& fix) const
{
	Fixed temp(this->toFloat() + fix.toFloat());
	return (temp);
}

Fixed Fixed::operator-(const Fixed& fix) const
{
	Fixed temp(this->toFloat() - fix.toFloat());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &fix) const
{
	Fixed temp(this->toFloat() * fix.toFloat());
	return (temp);
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	Fixed temp(this->toFloat() / fix.toFloat());
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	this->fixed_point++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->fixed_point--;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed ref(*this);
	this->fixed_point++;
	return (ref);
}

const Fixed Fixed::operator--(int)
{
	const Fixed ref(*this);
	this->fixed_point--;
	return (ref);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}