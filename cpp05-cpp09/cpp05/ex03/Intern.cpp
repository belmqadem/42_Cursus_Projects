#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern) {
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern) {
	std::cout << "Intern Copy assignment operator called" << std::endl;
	(void)intern;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::createShrubberyForm(std::string const &target) const {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string const &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) const {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
    struct FormType {
        std::string name;
        AForm *(Intern::*create)(std::string const &) const;
    };
    FormType forms[] = {
        {"shrubbery creation", &Intern::createShrubberyForm},
        {"robotomy request", &Intern::createRobotomyForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm},
    };
    for (int i = 0; i < 3; ++i) {
        if (forms[i].name == formName) {
            std::cout << BOLD_BLUE "Intern creates " << formName << RESET << std::endl;
            return (this->*forms[i].create)(target);
        }
    }
    std::cerr << BOLD_RED "Intern couldn't find the form: " << formName << RESET << std::endl;
    return NULL;
}