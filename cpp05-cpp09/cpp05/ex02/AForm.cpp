#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "AForm Default constructor caleed" << std::endl;
}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute) : name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "AForm Parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->is_signed = other.is_signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

std::string const AForm::getName() const {
	return name;
}

bool AForm::isSigned() const {
	return is_signed;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	std::cout << BOLD_WHITE << "Signing " << name << " ..." << RESET << std::endl;
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return BOLD_RED "Grade is too high" RESET;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return BOLD_RED "Grade is too low" RESET;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return BOLD_RED "Form is not signed" RESET;
}

std::ostream &operator << (std::ostream &out, AForm const &form) {
	out << BOLD_WHITE "Form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << RESET << std::endl;
	out << BOLD_BLUE "Grade to sign: " << form.getGradeToSign() << RESET << std::endl;
	out << BOLD_BLUE "Grade to execute: " << form.getGradeToExecute() << RESET << std::endl;
	return out;
}