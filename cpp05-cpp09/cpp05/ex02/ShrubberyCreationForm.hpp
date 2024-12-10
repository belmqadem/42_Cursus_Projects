#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string const target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};

#endif