#include "Weapon.hpp"

Weapon::Weapon(std::string type) : Type(type) {}

const std::string &Weapon::getType(void) const { return Type; }

void Weapon::setType(const std::string& type) { Type = type; }
