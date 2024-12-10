#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat1("Corleon", 2);
		std::cout << "Before: " << bureaucrat1 << std::endl;
		bureaucrat1.increment();
		std::cout << "After increment: " << bureaucrat1 << std::endl;
		bureaucrat1.decrement();
		std::cout << "After decrement: " << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2(bureaucrat1);
        bureaucrat2.increment();
		std::cout << "After increment: " << bureaucrat2 << std::endl;
        bureaucrat2.increment();
		std::cout << "After increment: " << bureaucrat2 << std::endl;

		Bureaucrat bureaucrat3("Micheal", 151);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
