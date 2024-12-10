#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string const target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};

#endif