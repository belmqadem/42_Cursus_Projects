#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), Name("Unnamed") {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energypoints = ScavTrap::Energypoints;
    this->Attackdamage = FragTrap::Attackdamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name) {
    std::cout << "DiamondTrap name constructor called" << std::endl;
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energypoints = ScavTrap::Energypoints;
    this->Attackdamage = FragTrap::Attackdamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::Name), ScavTrap(other), FragTrap(other), Name(other.Name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::Name = other.ClapTrap::Name;
        this->Name = other.Name;
        this->Hitpoints = other.Hitpoints;
        this->Energypoints = other.Energypoints;
        this->Attackdamage = other.Attackdamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << YELLOW "DiamondTrap name:\t" << this->Name << RESET << std::endl;
	std::cout << YELLOW "ClarTrap name:\t\t" << ClapTrap::Name << RESET << std::endl;
}
