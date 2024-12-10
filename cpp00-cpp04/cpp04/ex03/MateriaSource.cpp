#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		storedMateria[i] = NULL;
		activeMateria[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        storedMateria[i] = other.storedMateria[i]->clone();
        activeMateria[i] = storedMateria[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    std::cout << "MateriaSource copy assignment called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete storedMateria[i];
            delete activeMateria[i];
            storedMateria[i] = NULL;
            activeMateria[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (other.storedMateria[i]) {
                storedMateria[i] = other.storedMateria[i]->clone();
            } else {
                storedMateria[i] = NULL;
            }
            activeMateria[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (storedMateria[i]) delete storedMateria[i];
        if (activeMateria[i]) delete activeMateria[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (!materia) {
        std::cout << BOLD_RED "Error: Null materia provided." RESET << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!storedMateria[i]) {
            storedMateria[i] = materia->clone();
            std::cout << BOLD_WHITE "Materia of type " << materia->getType() << " stored in slot " << i << "." RESET << std::endl;
            delete materia;
            return;
        }
    }
    std::cout << BOLD_YELLOW "Storage full: No available slot to learn new materia of type " << materia->getType() << "." RESET << std::endl;
    delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++) {
        if (storedMateria[i] && storedMateria[i]->getType() == type) {
            if (activeMateria[i])
                delete activeMateria[i];
            activeMateria[i] = storedMateria[i]->clone();
            std::cout << BOLD_MAGENTA "New instance of " << type << " materia created." RESET << std::endl;
            return activeMateria[i];
        }
    }
    std::cout << BOLD_RED "Error: Materia type '" << type << "' is unknown or not learned." RESET << std::endl;
    return NULL;
}