#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria* storedMateria[4];
        AMateria* activeMateria[4];
    public :
        MateriaSource();
        MateriaSource( const MateriaSource &other );
        MateriaSource &operator=( const MateriaSource &other );
        ~MateriaSource();
        void learnMateria( AMateria * );
        AMateria *createMateria( std::string const &type );
};

#endif