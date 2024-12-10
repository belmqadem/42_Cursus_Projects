#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &ref);
		Intern &operator=(const Intern &ref);
		~Intern();
		AForm *createShrubberyForm(std::string const &target) const;
		AForm *createRobotomyForm(std::string const &target) const;
		AForm *createPresidentialPardonForm(std::string const &target) const;
		AForm *makeForm(std::string const &formName, std::string const &target) const;
};

#endif