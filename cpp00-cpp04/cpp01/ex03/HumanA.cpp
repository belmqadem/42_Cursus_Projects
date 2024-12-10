#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : WeaponA(weapon), Name(name) {}

void	HumanA::attack(void)
{
	std::cout << GREEN << this->Name << RESET " attacks with their " BLUE << this->WeaponA.getType() << RESET << std::endl;
}
