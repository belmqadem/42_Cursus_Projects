#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type( "Undefined Wrong Animal" ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : type(other.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if ( this != &other ) {
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << BOLD_GREEN "The wrong animal makes no sound [---]" RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
