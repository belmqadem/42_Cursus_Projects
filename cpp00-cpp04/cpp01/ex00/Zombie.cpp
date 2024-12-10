#include "Zombie.hpp"

Zombie::Zombie(const std::string name) : name(name) {}

void	Zombie::announce(void)
{
	std::cout << name << ":" GREEN " BraiiiiiiinnnzzzZ..." RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << RED " Is dead" RESET << std::endl;
}
