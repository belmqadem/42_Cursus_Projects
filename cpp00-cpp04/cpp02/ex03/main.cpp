#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point p1(5.0f, 5.0f);
    Point p2(10.0f, 10.0f);
    Point p3(5.0f, 0.0f);

    std::cout << "Point inside triangle: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "Point outside triangle: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, p3) << std::endl;

    return 0;
}
