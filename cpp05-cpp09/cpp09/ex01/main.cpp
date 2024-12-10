#include "RPN.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << USAGE << std::endl;
		return 1;
	}

	RPN rpn(av[1]);
	rpn.calculate();
	rpn.printResult();

	return 0;
}