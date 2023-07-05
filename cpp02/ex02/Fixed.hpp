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
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fix);
		int GetRawBits(void) const;
		void SetRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(const Fixed& fix) const;
		bool operator<(const Fixed& fix) const;
		bool operator>=(const Fixed& fix) const;
		bool operator<=(const Fixed& fix) const;
		bool operator==(const Fixed& fix) const;
		bool operator!=(const Fixed& fix) const;
		Fixed& operator=(const Fixed& fix);
		Fixed operator+(const Fixed& fix) const;
		Fixed operator-(const Fixed& fix) const;
		Fixed operator*(const Fixed &fix) const;
		Fixed operator/(const Fixed &fix) const;
		Fixed& operator++(void);
		Fixed& operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);
		static Fixed &min(Fixed &fix1, Fixed &fix2);
		static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
		static Fixed &max(Fixed &fix1, Fixed &fix2);
		static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);
#endif