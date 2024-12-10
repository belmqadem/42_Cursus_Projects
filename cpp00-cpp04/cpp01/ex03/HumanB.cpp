#include "HumanB.hpp"

HumanB::HumanB(std::string name) : Name(name), WeaponB(NULL) {}

void	HumanB::setWeapon(Weapon &weapon) { WeaponB = &weapon; }

void	HumanB::attack(void)
{
	if (WeaponB)
		std::cout << GREEN << this->Name << RESET " attacks with their " BLUE << this->WeaponB->getType() << RESET << std::endl;
	else
		std::cout << RED "No weapon set" RESET << std::endl;
}