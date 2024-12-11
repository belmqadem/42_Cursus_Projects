#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int> &vecSequence) : vecSequence(vecSequence) {}

PmergeMe::PmergeMe(const std::deque<int> &deqSequence) : deqSequence(deqSequence) {}

PmergeMe::PmergeMe(const PmergeMe &other) : vecSequence(other.vecSequence), deqSequence(other.deqSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vecSequence = other.vecSequence;
		deqSequence = other.deqSequence;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool validateInput(const std::string &input)
{
	std::istringstream iss(input);
	std::string token;
	std::vector<int> numbers;

	while (iss >> token)
	{
		for (size_t i = 0; i < token.size(); ++i)
			if (!isdigit(token[i]))
			{
				if (token[i] != '+')
					return false;
				else if (i != 0)
					return false;
			}
		if ((token.length() == 10 && token > "2147483647"))
			return false;
		int number = std::atoi(token.c_str());
		numbers.push_back(number);
	}
	return !numbers.empty();
}

std::vector<std::pair<int, int> > createPairs(const std::vector<int> &sequence)
{
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		if (i + 1 < sequence.size())
		{
			int first = sequence[i];
			int second = sequence[i + 1];
			if (first > second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
			pairs.push_back(std::make_pair(sequence[i], -1));
	}
	return pairs;
}

void mergeSort(std::vector<int> &sequence, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t mid = left + (right - left) / 2;
	mergeSort(sequence, left, mid);
	mergeSort(sequence, mid + 1, right);

	std::vector<int> temp;
	size_t i = left;
	size_t j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (sequence[i] < sequence[j])
			temp.push_back(sequence[i++]);
		else
			temp.push_back(sequence[j++]);
	}
	while (i <= mid)
		temp.push_back(sequence[i++]);
	while (j <= right)
		temp.push_back(sequence[j++]);

	std::copy(temp.begin(), temp.end(), sequence.begin() + left);
}

void PmergeMe::sortVector()
{
	std::vector<std::pair<int, int> > pairs = createPairs(vecSequence);

	std::vector<int> leaders, smaller;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		leaders.push_back(pairs[i].second);
		smaller.push_back(pairs[i].first);
	}

	leaders.erase(std::remove(leaders.begin(), leaders.end(), -1), leaders.end());

	mergeSort(leaders, 0, leaders.size() - 1);

	for (size_t i = 0; i < smaller.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(leaders.begin(), leaders.end(), smaller[i]);
		leaders.insert(pos, smaller[i]);
	}

	vecSequence = leaders;
}

std::deque<std::pair<int, int> > createPairs(const std::deque<int> &sequence)
{
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		if (i + 1 < sequence.size())
		{
			int first = sequence[i];
			int second = sequence[i + 1];
			if (first > second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
			pairs.push_back(std::make_pair(sequence[i], -1));
	}
	return pairs;
}

void mergeSort(std::deque<int> &sequence, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t mid = left + (right - left) / 2;
	mergeSort(sequence, left, mid);
	mergeSort(sequence, mid + 1, right);

	std::deque<int> temp;
	size_t i = left;
	size_t j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (sequence[i] < sequence[j])
			temp.push_back(sequence[i++]);
		else
			temp.push_back(sequence[j++]);
	}
	while (i <= mid)
		temp.push_back(sequence[i++]);
	while (j <= right)
		temp.push_back(sequence[j++]);

	std::copy(temp.begin(), temp.end(), sequence.begin() + left);
}

void PmergeMe::sortDeque()
{
	std::deque<std::pair<int, int> > pairs = createPairs(deqSequence);

	std::deque<int> leaders, smaller;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		leaders.push_back(pairs[i].second);
		smaller.push_back(pairs[i].first);
	}

	leaders.erase(std::remove(leaders.begin(), leaders.end(), -1), leaders.end());

	mergeSort(leaders, 0, leaders.size() - 1);

	for (size_t i = 0; i < smaller.size(); ++i)
	{
		std::deque<int>::iterator pos = std::lower_bound(leaders.begin(), leaders.end(), smaller[i]);
		leaders.insert(pos, smaller[i]);
	}

	deqSequence = leaders;
}

void PmergeMe::printSequence(const std::string &prefix) const
{
	if (prefix == "After: ")
		std::cout << BOLD_WHITE;
	std::cout << prefix;
	for (std::vector<int>::const_iterator it = vecSequence.begin(); it != vecSequence.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}