#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define RESET			"\033[0m"
#define BOLD_GREEN		"\033[1;32m"

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal& other );
		WrongAnimal &operator = ( const WrongAnimal& other );
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};

#endif