#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

#define R	"\033[0m"
#define BM	"\033[1;35m"
#define BC	"\033[1;36m"

typedef unsigned long uintptr_t;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &);
        Serializer &operator=(const Serializer &);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif