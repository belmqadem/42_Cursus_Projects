#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#define RESET			"\033[0m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_MAGENTA	"\033[1;35m"
#define BOLD_YELLOW     "\033[1;33m"
#define BOLD_RED        "\033[1;31m"
#define BOLD_CYAN       "\033[1;36m"
#define BOLD_WHITE      "\x1b[1;37m"

class AMateria {
    protected:
        std::string type;
    public:
        AMateria();
        AMateria( std::string const &type );
        AMateria( const AMateria &other );
        AMateria &operator = ( const AMateria &other );
        virtual ~AMateria();
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use( ICharacter &target );
};

#endif