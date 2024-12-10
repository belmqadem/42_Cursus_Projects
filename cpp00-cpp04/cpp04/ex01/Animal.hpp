#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET			"\033[0m"
#define CYAN			"\033[36m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_MAGENTA	"\033[1;35m"

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal( const Animal& other );
		Animal &operator = ( const Animal& other );
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif