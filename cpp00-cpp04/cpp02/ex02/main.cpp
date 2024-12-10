#include "Fixed.hpp"

int main() {
    Fixed a;
    std::cout << "a (default constructor): " << a << std::endl;

    Fixed b(10);
    std::cout << "b (int constructor with value 10): " << b << std::endl;

    Fixed c(5.05f);
    std::cout << "c (float constructor with value 5.05): " << c << std::endl;

    Fixed d(c);
    std::cout << "d (copy constructor from c): " << d << std::endl;

    a = b;
    std::cout << "a (after assignment from b): " << a << std::endl;

    std::cout << "c.toFloat(): " << c.toFloat() << std::endl;
    std::cout << "b.toInt(): " << b.toInt() << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "b + c: " << (b + c) << std::endl;
    std::cout << "b - c: " << (b - c) << std::endl;
    std::cout << "b * c: " << (b * c) << std::endl;
    std::cout << "b / c: " << (b / c) << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a (after a++): " << a << std::endl;

    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a (after a--): " << a << std::endl;

    Fixed e(42.42f);
    Fixed f(21.21f);
    std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

    const Fixed g(12.12f);
    const Fixed h(99.99f);
    std::cout << "const min(g, h): " << Fixed::min(g, h) << std::endl;
    std::cout << "const max(g, h): " << Fixed::max(g, h) << std::endl;

    return 0;
}