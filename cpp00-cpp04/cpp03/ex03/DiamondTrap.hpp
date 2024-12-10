#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap & );
		DiamondTrap& operator = ( const DiamondTrap & );
		~DiamondTrap();
		void whoAmI();
};

#endif