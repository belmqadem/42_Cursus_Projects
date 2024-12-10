#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << BOLD_CYAN "========== Testing MateriaSource and Learning Materias ==========" RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(NULL);
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    
    std::cout << BOLD_CYAN "\n========== Creating Characters and Equipping Materia ==========" RESET << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    me->equip(ice);
    me->equip(cure);
    me->equip(cure);
    me->equip(NULL);
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));

    std::cout << BOLD_CYAN "\n========== Testing Use Function ==========" RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    
    std::cout << BOLD_CYAN "\n========== Testing Unequip Function ==========" RESET << std::endl;
    me->unequip(1);
    me->use(1, *bob);
    me->unequip(1);
    me->unequip(4);

    std::cout << BOLD_CYAN "\n========== Testing Unknown Materia Creation ==========" RESET << std::endl;
    src->createMateria("Salt");

    std::cout << BOLD_CYAN "\n========== Deleting Characters and Sources ==========" RESET << std::endl;
    delete bob;
    delete me;
    delete src;
    return 0;
}
