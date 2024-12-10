#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

#define RESET "\033[0m"
#define RED "\033[31m"

template <typename T>
void easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error(RED "Value not found" RESET);
    std::cout << "Value found: " << *it << std::endl;
}

#endif