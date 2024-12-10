#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat1("John", 10);
        ShrubberyCreationForm form1("home");
        bureaucrat1.executeForm(form1);
        form1.beSigned(bureaucrat1);
        bureaucrat1.executeForm(form1);
        std::cout << std::endl;

        RobotomyRequestForm form2("Alice");
        form2.beSigned(bureaucrat1);
        bureaucrat1.executeForm(form2);
        std::cout << std::endl;

        PresidentialPardonForm form3("Bob");
        form3.beSigned(bureaucrat1);
        bureaucrat1.executeForm(form3);
        std::cout << std::endl;

        Bureaucrat bureaucrat2("Jane", 2);
        bureaucrat2.executeForm(form3);
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}