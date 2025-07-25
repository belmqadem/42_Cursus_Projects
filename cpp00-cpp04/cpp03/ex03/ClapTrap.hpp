#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define CYAN		"\033[36m"
#define MAGENTA		"\033[35m"

class ClapTrap
{
	protected:
		std::string Name;
		unsigned int Hitpoints;
		unsigned int Energypoints;
		unsigned int Attackdamage;
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap & );
		ClapTrap& operator = ( const ClapTrap & );
		~ClapTrap();
		void attack( std::string const &target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};

#endif