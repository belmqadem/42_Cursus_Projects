#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request Form", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << BOLD_YELLOW << "Drilling noises" << RESET << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << BOLD_BLUE << executor.getName() << " has been robotomized" << RESET << std::endl;
	else
		std::cout << BOLD_RED << executor.getName() << " failed to robotomize" << RESET << std::endl;
}