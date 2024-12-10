#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("ST-1");
    scav.attack("Target A");
    std::cout << std::endl;

    ScavTrap scav2(scav);
    scav2.attack("Target B");
    scav2.guardGate();
    std::cout << std::endl;

    ScavTrap scav3("ST-15");
    scav3 = scav2;
    scav3.attack("Target C");
    std::cout << std::endl;

    scav.takeDamage(30);
    scav.takeDamage(70);
    scav.takeDamage(10);
    scav.beRepaired(20);
    scav.attack("Target B");
    scav.attack("Target C");
    scav.takeDamage(10);
    scav.beRepaired(15);
    scav.guardGate();
    std::cout << std::endl;

    return 0;
}
