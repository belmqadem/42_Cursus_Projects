#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		void announce(void);
		void setName(std::string name);
		~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
