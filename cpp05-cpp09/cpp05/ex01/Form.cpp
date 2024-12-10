#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form Default constructor caleed" << std::endl;
}

Form::Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute) : name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "Form Parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->is_signed = other.is_signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

std::string const Form::getName() const {
	return name;
}

bool Form::isSigned() const {
	return is_signed;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	std::cout << BOLD_WHITE << "Signing " << name << " ..." << RESET << std::endl;
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return BOLD_RED "Grade is too high" RESET;
}

const char *Form::GradeTooLowException::what() const throw() {
	return BOLD_RED "Grade is too low" RESET;
}

std::ostream &operator << (std::ostream &out, Form const &form) {
	out << BOLD_WHITE "Form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << RESET << std::endl;
	out << BOLD_BLUE "Grade to sign: " << form.getGradeToSign() << RESET << std::endl;
	out << BOLD_BLUE "Grade to execute: " << form.getGradeToExecute() << RESET << std::endl;
	return out;
}