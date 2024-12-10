#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD_WHITE "\x1b[1;37m"

#define ERROR RED "Error" RESET
#define USAGE RED "Usage: ./PmergeMe [sequence]" RESET

class PmergeMe
{
private:
	std::vector<int> vecSequence;
	std::deque<int> deqSequence;

public:
	PmergeMe();
	PmergeMe(const std::vector<int> &vecSequence);
	PmergeMe(const std::deque<int> &deqSequence);
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	void sortVector();
	void sortDeque();

	void printSequence(const std::string &prefix) const;
};

bool validateInput(const std::string &input);

#endif