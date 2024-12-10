#include "FragTrap.hpp"

int main() {
    FragTrap fragOne("FT-50");
    fragOne.attack("Target A");
    std::cout << std::endl;

    FragTrap fragTwo(fragOne);
    fragTwo.attack("Target B");
    fragTwo.highFivesGuys();
    std::cout << std::endl;

    FragTrap fragThree = fragOne;
    fragThree.attack("Target C");
    std::cout << std::endl;

    FragTrap frag("FT-1");
    frag.highFivesGuys();
    frag.attack("Target A");
    frag.takeDamage(30);
    frag.attack("Target B");
    frag.takeDamage(5);
    frag.beRepaired(15);
    std::cout << std::endl;

    return 0;
}
