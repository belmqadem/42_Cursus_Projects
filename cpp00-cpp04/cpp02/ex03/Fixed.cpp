#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed( const int value ) {
	this->value = value << this->fractional_bits;
}

Fixed::Fixed( const float value ) {
	this->value = roundf(value * (1 << this->fractional_bits));
}

Fixed::Fixed( const Fixed &other ) {
	this->value = other.getRawBits();
}

Fixed &Fixed::operator = ( const Fixed &other ) {
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const {
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->value / (1 << this->fractional_bits);
}

int Fixed::toInt( void ) const {
	return this->value >> this->fractional_bits;
}

bool Fixed::operator > ( const Fixed &fixed ) const {
	return this->value > fixed.getRawBits();
}

bool Fixed::operator < ( const Fixed &fixed ) const {
	return this->value < fixed.getRawBits();
}

bool Fixed::operator >= ( const Fixed &fixed ) const {
	return this->value >= fixed.getRawBits();
}

bool Fixed::operator <= ( const Fixed &fixed ) const {
	return this->value <= fixed.getRawBits();
}

bool Fixed::operator == ( const Fixed &fixed ) const {
	return this->value == fixed.getRawBits();
}

bool Fixed::operator != ( const Fixed &fixed ) const {
	return this->value != fixed.getRawBits();
}

Fixed Fixed::operator + ( const Fixed &fixed ) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - ( const Fixed &fixed ) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * ( const Fixed &fixed ) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator ++ ( void ) {
	this->value++;
	return *this;
}

Fixed Fixed::operator ++ ( int ) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed &Fixed::operator -- ( void ) {
	this->value--;
	return *this;
}

Fixed Fixed::operator -- ( int ) {
	Fixed temp = *this;
	--*this;
	return temp;
}

Fixed &Fixed::min ( Fixed &a, Fixed &b ) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
	return (a > b) ? a : b;
}

Fixed Fixed::abs( const Fixed &fixed ) {
	Fixed result;
	result.value = (fixed.value < 0) ? -fixed.value : fixed.value;
	return result;
}

std::ostream &operator << ( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}