#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#define RESET "\033[0m"
#define RED "\033[31m"

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

		bool operator > ( const Fixed &fixed ) const;
		bool operator < ( const Fixed &fixed ) const;
		bool operator >= ( const Fixed &fixed ) const;
		bool operator <= ( const Fixed &fixed ) const;
		bool operator == ( const Fixed &fixed ) const;
		bool operator != ( const Fixed &fixed ) const;

		Fixed operator + ( const Fixed &fixed ) const;
		Fixed operator - ( const Fixed &fixed ) const;
		Fixed operator * ( const Fixed &fixed ) const;
		Fixed operator / ( const Fixed &fixed ) const;

		Fixed &operator ++ ( void );
		Fixed operator ++ ( int );
		Fixed &operator -- ( void );
		Fixed operator -- ( int );

		static Fixed &min( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );

		static Fixed abs( const Fixed &fixed );
};

std::ostream &operator << ( std::ostream &out, const Fixed &fixed );

#endif