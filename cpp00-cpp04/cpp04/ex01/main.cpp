#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	int size = 4;
    Animal* animals[size];

    std::cout << BOLD_MAGENTA "*** Dogs Construction ***" RESET << std::endl;
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    std::cout << std::endl;
    std::cout << BOLD_MAGENTA "*** Cats Construction ***" RESET << std::endl;
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }    
    std::cout << std::endl;

    std::cout << BOLD_MAGENTA "*** Testing Deep Copy with Dog ***" RESET << std::endl;
    Dog basicDog;
    {
        Dog tmpDog = basicDog;
        tmpDog.makeSound();
    }
    basicDog.makeSound();
    std::cout << std::endl;

    std::cout << BOLD_MAGENTA "*** Testing Deep Copy with Cat ***" RESET << std::endl;
    Cat basicCat;
    {
        Cat tmpCat = basicCat;
        tmpCat.makeSound();
    }
    basicCat.makeSound();
    std::cout << std::endl;

    std::cout << BOLD_MAGENTA "*** Animals Make Sound ***" RESET << std::endl;
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << BOLD_MAGENTA "*** Destruction ***" RESET << std::endl;
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    return (0);
}