#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed Zombie") {}

void	Zombie::announce(void)
{
	std::cout << name << ":" GREEN " BraiiiiiiinnnzzzZ..." RESET << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << RED " Is dead" RESET << std::endl;
}
