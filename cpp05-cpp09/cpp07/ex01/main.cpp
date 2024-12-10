#include "iter.hpp"

void fo(int const &i)
{
    std::cout << "int value: " YELLOW << i << RESET << std::endl;
}

void foo(char const &c)
{
    std::cout << "char value: " YELLOW << c << RESET << std::endl;
}

void fooo(std::string const &s)
{
    std::cout << "string value: " YELLOW << s << RESET << std::endl;
}

int main()
{
    int tab[] = {23, 10, 42, 13, 37, 99};
    ::iter(tab, sizeof(tab) / sizeof(tab[0]), fo);

    std::cout << std::endl;

    char tab2[] = {'a', 'b', 'c'};
    ::iter(tab2, sizeof(tab2) / sizeof(tab2[0]), foo);

    std::cout << std::endl;

    std::string tab3[] = {"valarmorghulis", "valardohaeris"};
    ::iter(tab3, sizeof(tab3) / sizeof(tab3[0]), fooo);

    return 0;
}