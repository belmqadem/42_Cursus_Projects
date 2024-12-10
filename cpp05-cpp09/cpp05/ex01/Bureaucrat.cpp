#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name ( "Default" ), Grade ( 150 ) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const Name, int Grade ) : Name ( Name ) {
	std::cout << "Bureaucrat Parameterized constructor called" << std::endl;
	if (Grade < 1)
        throw GradeTooHighException();
    if (Grade > 150)
        throw GradeTooLowException();
    this->Grade = Grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &other ) : Name ( other.Name ), Grade ( other.Grade ) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = ( Bureaucrat const &other ) {
	std::cout << "Bureaucrat Copy Assignment operator called" << std::endl;
	if ( this != &other ) {
		this->Grade = other.Grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string const Bureaucrat::getName() const {
	return Name;
}

int Bureaucrat::getGrade() const {
	return Grade;
}

void Bureaucrat::increment( void ) {
	std::cout << BOLD_YELLOW "Incrementing grade" RESET << std::endl;
	if (Grade == 1)
        throw GradeTooHighException();
	this->Grade --;
}

void Bureaucrat::decrement( void ) {
	std::cout << BOLD_YELLOW "Decrementing grade" RESET << std::endl;
	if (Grade == 150)
        throw GradeTooLowException();
	this->Grade ++;
}

void Bureaucrat::signForm(Form &form) const {
    try {
        form.beSigned(*this);
        std::cout << BOLD_YELLOW << this->getName() << " signed " << form.getName() << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << BOLD_RED << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return BOLD_RED "Grade is too high" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return BOLD_RED "Grade is too low" RESET;
}

std::ostream &operator << ( std::ostream &out, Bureaucrat const &other ) {
	out << BOLD_GREEN << other.getName() << ", bureaucrat grade " << other.getGrade() << RESET << std::endl;
	return out;
}