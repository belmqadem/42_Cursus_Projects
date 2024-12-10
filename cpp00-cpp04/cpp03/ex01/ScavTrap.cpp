#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = ( const ScavTrap &other ) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	if (this->Energypoints > 0) {
		std::cout << CYAN "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->Attackdamage << " points of damage!" RESET << std::endl;
		this->Energypoints--;
	} else {
		std::cout << YELLOW "ScavTrap " << this->Name << " is out of energy 🪫" RESET << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << MAGENTA "ScavTrap " << this->Name << " is now in Gate keeper mode." RESET << std::endl;
}