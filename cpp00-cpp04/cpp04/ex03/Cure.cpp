#include "Cure.hpp"

Cure::Cure() : AMateria( "cure" ) {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure &other ) : AMateria( other ) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=( const Cure &other ) {
    std::cout << "Cure copy assignment called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const {
    AMateria *newOne = new Cure();
    return newOne;
}

void Cure::use( ICharacter &target ) {
    std::cout << BOLD_GREEN "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}