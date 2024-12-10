#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

template <typename T>
class Array
{
private:
    T *array;
    unsigned int size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const &);
    Array &operator=(Array const &);
    ~Array();
    T &operator[](unsigned int i);
    const T &operator[](unsigned int i) const;
    unsigned int getSize() const;
};

template <typename T>
Array<T>::Array() : array(NULL), size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size(n)
{
    std::cout << "Array parameterized constructor called" << std::endl;
    for (unsigned int i = 0; i < n; i++)
    {
        array[i] = T();
    }
}

template <typename T>
Array<T>::Array(Array const &other) : array(NULL), size(0)
{
    std::cout << "Array copy constructor called" << std::endl;
    if (other.size > 0)
    {
        size = other.size;
        array = new T[size];
        for (unsigned int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &other)
    {
        delete[] array;
        size = other.size;
        array = (size > 0) ? new T[size] : NULL;
        for (unsigned int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete[] array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= size)
    {
        throw std::out_of_range(RED "index out of bounds" RESET);
    }
    return array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= size)
    {
        throw std::out_of_range(RED "index out of bounds" RESET);
    }
    return array[i];
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}

#endif
