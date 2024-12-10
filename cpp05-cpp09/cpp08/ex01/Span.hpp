#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"

typedef std::vector<int>::iterator ITER;

class Span
{
private:
    unsigned int N;
    std::vector<int> span;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();

    void addNumber(int number);
    void addRange(ITER begin, ITER end);
    int shortestSpan();
    int longestSpan();
    class SpanFull : public std::exception
    {
        virtual const char *what() const throw();
    };
    class NoNumberStored : public std::exception
    {
        virtual const char *what() const throw();
    };
    class NotEnoughNumbers : public std::exception
    {
        virtual const char *what() const throw();
    };
};

#endif