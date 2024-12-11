#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"

#define USAGE RED "Usage: ./RPN [expression]" RESET
#define ERR RED "Error: Invalid expression" RESET
#define ERR_DIV RED "Error: Division by zero" RESET

enum operators
{
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/'
};

class RPN
{
private:
	std::stack<int> stack;
	std::string expression;
	int result;

public:
	RPN();
	RPN(const std::string &expression);
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	void calculate();
	void printResult() const;
	bool is_valid(const std::string& token);
};

#endif