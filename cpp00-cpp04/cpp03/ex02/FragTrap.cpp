#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = ( const FragTrap &other ) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << MAGENTA "FragTrap " << this->Name << " says: Gimme five guys!" RESET << std::endl;
}