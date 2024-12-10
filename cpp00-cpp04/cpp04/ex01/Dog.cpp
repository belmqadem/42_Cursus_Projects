#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal( other ), brain(new Brain(*other.brain)) {
	std::cout <<  "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator = ( const Dog& other ) {
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << BOLD_GREEN "The dog makes a sound [haw haw]" RESET << std::endl;
}