#include "ClapTrap.hpp"

int main() {

    ClapTrap noone;
    noone.attack("target1");
    std::cout << std::endl;

    ClapTrap claptrap("CT-1");
    std::cout << std::endl;

    ClapTrap claptrap2( claptrap );
    claptrap2.attack("my target");
    std::cout << std::endl;

    ClapTrap claptrap3("XXT-00");
    claptrap3.attack("Enemy");
    std::cout << std::endl;

    claptrap3 = claptrap2;
    claptrap3.attack("Enemy");
    std::cout << std::endl;

    claptrap.attack("target1");
    claptrap.attack("target1");
    claptrap.attack("target1");
    claptrap.attack("target1");
    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.attack("target2");
    claptrap.takeDamage(10);
    claptrap.takeDamage(10);
    claptrap.attack("target3");
    claptrap.beRepaired(5);
    claptrap.takeDamage(2);
    claptrap.beRepaired(5);
    std::cout << std::endl;

    return 0;
}