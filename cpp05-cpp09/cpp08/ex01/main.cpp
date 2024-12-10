#include "Span.hpp"
#include <list>

int main()
{
    try
    {
        Span sp(10);
        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(1);
        sp.addRange(vec.begin(), vec.end());
        sp.addNumber(20);
        sp.addNumber(-8);
        std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span is: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}