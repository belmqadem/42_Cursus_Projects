#include "AMateria.hpp"

AMateria::AMateria() : type( "Undefined" ) {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria( std::string const &type ) : type( type ) {
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria( const AMateria &other ) : type( other.type ) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator = ( const AMateria &other ) {
    std::cout << "AMateria copy assignment called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
    return type;
}

void AMateria::use( ICharacter &target ) {
    std::cout << BOLD_GREEN "* uses a materia on " << target.getName() << " *" RESET << std::endl;
}