#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const name;
		bool is_signed;
		int const gradeToSign;
		int const gradeToExecute;
	public:
		AForm();
		AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
		AForm(const AForm &);
		AForm &operator=(const AForm &);
		virtual ~AForm();
		std::string const getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif