#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed & );
		Fixed &operator = ( const Fixed & );
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream &operator << ( std::ostream &out, const Fixed &fixed );

#endif