#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        easyfind(vec, 1);
        easyfind(vec, 3);
        easyfind(vec, 5);
        easyfind(vec, 6);
        easyfind(vec, 2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}