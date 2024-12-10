#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "Wrong Cat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator = ( const WrongCat& other ) {
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout <<  BOLD_GREEN "The wrong cat makes a sound [meow meow]" RESET << std::endl;
}