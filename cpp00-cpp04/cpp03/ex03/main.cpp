#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamondTrap("DT-8080");
    diamondTrap.attack("Target I");
    diamondTrap.takeDamage(35);
    diamondTrap.beRepaired(20);
    diamondTrap.guardGate();
    std::cout << std::endl;

    DiamondTrap diamondTrap2(diamondTrap);
    diamondTrap2.highFivesGuys();
    std::cout << std::endl;
    diamondTrap2.whoAmI();
    std::cout << std::endl;

    DiamondTrap diamondTrap3("DT-9090");
    diamondTrap3.whoAmI();
    std::cout << std::endl;

    diamondTrap3 = diamondTrap;
    diamondTrap3.attack("Target II");
    diamondTrap3.takeDamage(50);
    diamondTrap3.beRepaired(30);
    std::cout << std::endl;

    return 0;
}
