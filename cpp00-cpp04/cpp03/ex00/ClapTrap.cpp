#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Unnamed"), Hitpoints(10), Energypoints(10), Attackdamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : Name(name), Hitpoints(10), Energypoints(10), Attackdamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        this->Name = other.Name;
		this->Hitpoints = other.Hitpoints;
		this->Energypoints = other.Energypoints;
		this->Attackdamage = other.Attackdamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack( const std::string& target ) {
	if (this->Energypoints > 0) {
		std::cout << CYAN "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->Attackdamage << " points of damage!" RESET << std::endl;
		this->Energypoints--;
	} else {
		std::cout << YELLOW "ClapTrap " << this->Name << " is out of energy 🪫" RESET << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (amount > this->Hitpoints) {
		this->Hitpoints = 0;
		std::cout << RED "ClapTrap " << this->Name << " has been destroyed" << std::endl;
	} else {
		this->Hitpoints -= amount;
		std::cout << RED "ClapTrap " << this->Name << " takes " << amount << " points of damage!" RESET << std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->Energypoints > 0) {
		if (this->Hitpoints + amount > 10) {
			this->Hitpoints = 10;
		} else {
			this->Hitpoints += amount;
		}
		std::cout << GREEN "ClapTrap " << this->Name << " is repaired for " << amount << " points!" RESET<< std::endl;
		this->Energypoints--;
	} else {
		std::cout << YELLOW "ClapTrap " << this->Name << " is out of energy 🪫" RESET << std::endl;
	}
}