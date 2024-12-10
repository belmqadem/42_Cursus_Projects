#include "Span.hpp"

Span::Span() : N(INT_MAX) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->span = other.span;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this->span.size() < this->N)
		this->span.push_back(number);
	else
		throw Span::SpanFull();
}

void Span::addRange(ITER begin, ITER end)
{
	if (this->span.size() + std::distance(begin, end) <= this->N)
		this->span.insert(this->span.end(), begin, end);
	else
		throw Span::SpanFull();
}

int Span::shortestSpan()
{
	if (this->span.size() == 0)
		throw Span::NoNumberStored();
	if (this->span.size() == 1)
		throw Span::NotEnoughNumbers();

	std::vector<int> sorted = this->span;
	std::sort(sorted.begin(), sorted.end());
	int min = INT_MAX;
	for (ITER it = sorted.begin(); it != sorted.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
		{
			min = *(it + 1) - *it;
		}
	}
	return min;
}

int Span::longestSpan()
{
	if (this->span.size() == 0)
		throw Span::NoNumberStored();
	if (this->span.size() == 1)
		throw Span::NotEnoughNumbers();

	std::vector<int> sorted = this->span;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char *Span::SpanFull::what() const throw()
{
	return RED "Span is full" RESET;
}

const char *Span::NoNumberStored::what() const throw()
{
	return RED "Span is empty" RESET;
}

const char *Span::NotEnoughNumbers::what() const throw()
{
	return RED "Not enough numbers in span" RESET;
}