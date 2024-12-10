#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern randomIntern;
    AForm *form;

    std::cout << BOLD_YELLOW "\n[Test Case 1] Creating ShrubberyCreationForm:" RESET << std::endl;
    form = randomIntern.makeForm("shrubbery creation", "office");
    if (form) {
        std::cout << *form << std::endl;
        try { form->beSigned(Bureaucrat("Joe", 149)); }
        catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        delete form;
    }

    std::cout << BOLD_YELLOW "\n[Test Case 2] Creating RobotomyRequestForm:" RESET << std::endl;
    form = randomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << BOLD_YELLOW "\n[Test Case 3] Creating PresidentialPardonForm:" RESET << std::endl;
    form = randomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    if (form) {
        std::cout << *form << std::endl;
        Bureaucrat chief("Zaphod Beeblebrox", 1);
        try { chief.signForm(*form); }
        catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        delete form;
    }

    std::cout << BOLD_YELLOW "\n[Test Case 4] Creating an invalid form:" RESET << std::endl;
    form = randomIntern.makeForm("invalid form", "Nowhere");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << BOLD_YELLOW "\n[Test Case 5] Repeatedly creating forms to ensure no memory leak:" RESET << std::endl;
    for (int i = 0; i < 3; ++i) {
        form = randomIntern.makeForm("robotomy request", "RepeatTest");
        if (form) {
            std::cout << *form;
            delete form;
            std::endl(std::cout);
        }
    }
    return 0;
}
