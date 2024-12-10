#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define BLUE	"\033[34m"

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
};

#endif