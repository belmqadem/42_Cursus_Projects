#include "Character.hpp"

Character::Character() : name( "Unknown Character" ) {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
        saved[i] = NULL;
    }
}

Character::Character( const std::string &name ) : name( name ){
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
        saved[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
            saved[i] = inventory[i];
        } else {
            inventory[i] = NULL;
            saved[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other) {
    std::cout << "Character copy assignment called" << std::endl;
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
                saved[i] = inventory[i];
            } else {
                inventory[i] = NULL;
                saved[i] = NULL;
            }
        }
    }
    return *this;
}


Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (saved[i] && saved[i] != inventory[i]) {
            delete saved[i];
            saved[i] = NULL;
        }
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    if (!m) {
        std::cout << BOLD_RED "Error: Attempted to equip a null materia." RESET << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m->clone();
            saved[i] = inventory[i];
            std::cout << BOLD_WHITE "+++ Successfully equipped " << m->getType() << " in slot " << i << " +++" RESET << std::endl;
            return;
        }
    }
    std::cout << BOLD_RED "Inventory full: Cannot equip " << m->getType() << " as all slots are occupied." RESET << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << BOLD_RED "Error: Index " << idx << " is out of bounds. Valid slots are 0 to 3." RESET << std::endl;
        return;
    }
    if (!inventory[idx]) {
        std::cout << BOLD_YELLOW "Warning: No materia found in slot " << idx << " to unequip." RESET << std::endl;
        return;
    }
    inventory[idx] = NULL;
    std::cout << BOLD_WHITE "--- Unequipped materia from slot " << idx << " successfully ---" RESET << std::endl;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << BOLD_RED "Error: Index " << idx << " is out of bounds. Valid slots are 0 to 3." RESET << std::endl;
        return;
    }
    if (!inventory[idx]) {
        std::cout << BOLD_YELLOW "Warning: No materia found in slot " << idx << " to use." RESET << std::endl;
        return;
    }
    inventory[idx]->use(target);
}