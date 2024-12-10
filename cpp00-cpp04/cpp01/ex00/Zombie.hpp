#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string name);
		void announce(void);
		~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
