#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <functional>
#include "AForm.hpp"

#define RESET			"\033[0m"
#define BOLD_RED		"\033[1;31m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_BLUE		"\033[1;34m"
#define BOLD_YELLOW		"\033[1;33m"
#define BOLD_WHITE      "\x1b[1;37m"

class AForm;

class Bureaucrat {
	private:
		std::string const Name;
		int Grade;
	public:
		Bureaucrat();
		Bureaucrat( std::string const Name, int Grade );
		Bureaucrat( Bureaucrat const & );
		Bureaucrat &operator = ( Bureaucrat const & );
		~Bureaucrat();
		std::string const getName() const;
		int getGrade() const;
		void increment(void);
		void decrement(void);
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif