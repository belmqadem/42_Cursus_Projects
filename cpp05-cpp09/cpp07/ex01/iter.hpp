#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"

template <typename T, typename Func>
void iter(T *array, int length, Func function)
{
    if (!array || length <= 0)
    {
        return;
    }
    for (int i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}

#endif