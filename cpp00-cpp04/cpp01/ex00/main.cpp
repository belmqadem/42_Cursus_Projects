#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombieOne("Foo");
	zombieOne.announce();

	Zombie *zombieTwo = newZombie("Boo");
	zombieTwo->announce();

	randomChump("Coo");

	delete zombieTwo;
	return (0);
}
