#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->fractional_bits;
}

Fixed::Fixed( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->fractional_bits));
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed &Fixed::operator = ( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
}

float Fixed::toFloat( void ) const {
	float floatNum;
	floatNum = (float)this->value / (1 << this->fractional_bits);
	return floatNum;
}

int Fixed::toInt( void ) const {
	int intNum;
	intNum = this->value >> this->fractional_bits;
	return intNum;
}

std::ostream &operator << ( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}
