#ifndef HumanA_HPP
#define HumanA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		&WeaponA;
		std::string	Name;
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack(void);
};

#endif
