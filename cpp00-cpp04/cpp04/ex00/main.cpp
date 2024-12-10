#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << BOLD_MAGENTA "-------------------------" << std::endl;
	std::cout << "Test with virtual keyword" << std::endl;
	std::cout << "-------------------------" RESET<< std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << CYAN "first animal type: " RESET << dog->getType() << std::endl;
	std::cout << CYAN "second animal type: " RESET << cat->getType() << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	std::cout << BOLD_MAGENTA "----------------------------" << std::endl;
	std::cout << "Test without virtual keyword" << std::endl;
	std::cout << "----------------------------" RESET<< std::endl;
	std::cout << std::endl;

	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << std::endl;

	wanimal->makeSound();
	wcat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete meta;
	delete wcat;
	delete wanimal;
	return 0;
}
