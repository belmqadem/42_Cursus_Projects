#ifndef HumanB_HPP
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	Name;
		Weapon		*WeaponB;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif
