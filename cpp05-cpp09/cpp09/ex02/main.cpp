#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cerr << USAGE << std::endl;
		return 1;
	}

	std::vector<int> vecSequence;
	std::deque<int> deqSequence;

	for (int i = 1; i < ac; ++i)
	{
		if (!validateInput(av[i]))
		{
			std::cerr << ERROR << std::endl;
			return 1;
		}
		vecSequence.push_back(atoi(av[i]));
		deqSequence.push_back(atoi(av[i]));
	}

	PmergeMe vecPmergeMe(vecSequence);
	PmergeMe deqPmergeMe(deqSequence);

	vecPmergeMe.printSequence("Before: ");

	clock_t start = clock();
	vecPmergeMe.sortVector();
	clock_t end = clock();
	double elapsedVec = double(end - start) * 1e6 / double(CLOCKS_PER_SEC);

	start = clock();
	deqPmergeMe.sortDeque();
	end = clock();
	double elapsedDeq = double(end - start) * 1e6 / double(CLOCKS_PER_SEC);

	vecPmergeMe.printSequence("After: ");

	std::cout << "Time to process a range of " << vecSequence.size()
			  << " elements with std::vector : " GREEN << std::fixed << elapsedVec << " us" RESET << std::endl;
	std::cout << "Time to process a range of " << deqSequence.size()
			  << " elements with std::deque : " GREEN << std::fixed << elapsedDeq << " us" RESET << std::endl;
}