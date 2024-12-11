#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &expression) : expression(expression), result(0)
{
	this->stack = std::stack<int>();
}

RPN::RPN(const RPN &other) : stack(other.stack), expression(other.expression), result(other.result) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->stack = other.stack;
		this->expression = other.expression;
		this->result = other.result;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::is_valid(const std::string &token)
{
	return token.length() == 1 && isdigit(token[0]);
}

void RPN::calculate()
{
	std::istringstream iss(this->expression);
	std::string token;
	int a, b;

	while (iss >> token)
	{
		if (token.length() == 1 && !isdigit(token[0]))
		{
			if (this->stack.size() < 2)
			{
				std::cerr << ERR << std::endl;
				exit(1);
			}
			b = this->stack.top();
			this->stack.pop();
			a = this->stack.top();
			this->stack.pop();
			switch (token[0])
			{
			case ADD:
				this->stack.push(a + b);
				break;
			case SUB:
				this->stack.push(a - b);
				break;
			case MUL:
				this->stack.push(a * b);
				break;
			case DIV:
				if (b == 0)
				{
					std::cerr << ERR_DIV << std::endl;
					exit(1);
				}
				this->stack.push(a / b);
				break;
			default:
				std::cerr << ERR << std::endl;
				exit(1);
			}
		}
		else if (is_valid(token))
		{
			this->stack.push(std::atoi(token.c_str()));
		}
		else
		{
			std::cerr << ERR << std::endl;
			exit(1);
		}
	}
	if (this->stack.size() != 1)
	{
		std::cerr << ERR << std::endl;
		exit(1);
	}
	this->result = this->stack.top();
}

void RPN::printResult() const
{
	std::cout << this->result << std::endl;
}