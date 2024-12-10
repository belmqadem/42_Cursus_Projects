#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;
    std::cout << BOLD_CYAN "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::cout << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << BOLD_CYAN "Before swap: c = " << c << ", d = " << d << RESET << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    std::cout << std::endl;

    float e = 42.42;
    float f = 21.21;
    std::cout << BOLD_CYAN "Before swap: e = " << e << ", f = " << f << RESET << std::endl;
    ::swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    return 0;
}