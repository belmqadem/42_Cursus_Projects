#ifndef	WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define RED		"\033[31m"

class Weapon {
	private:
		std::string Type;
	public:
		Weapon(std::string type);
		const std::string &getType(void) const;
		void setType(const std::string& type);
};

#endif
