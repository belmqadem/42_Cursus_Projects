#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define RESET			"\033[0m"
#define YELLOW			"\033[33m"

class Fixed {
	private:
		int value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed( const Fixed & );
		Fixed &operator = ( const Fixed & );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif