#include <iostream>
#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"

int main(void)
{
	std::string sayHi = "HI THIS IS BRAIN";
	std::string *ptr = &sayHi;
	std::string &ref = sayHi;

	std::cout << "Memory address of the string variable: " GREEN << &sayHi << RESET << std::endl;
	std::cout << "Memory address held by stringPTR: " GREEN << ptr << RESET << std::endl;
	std::cout << "Memory address held by stringREF: " GREEN << &ref << RESET << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string variable: " BLUE << sayHi << RESET << std::endl;
	std::cout << "Value pointed to by stringPTR: " BLUE << *ptr << RESET << std::endl;
	std::cout << "Value pointed to by stringREF: " BLUE << ref << RESET << std::endl;
}
