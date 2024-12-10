#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

#define RESET			"\033[0m"
#define CYAN			"\033[36m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_MAGENTA	"\033[1;35m"

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal( const AAnimal& other );
		AAnimal &operator = ( const AAnimal& other );
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif