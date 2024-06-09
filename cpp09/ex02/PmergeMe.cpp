#include "PmergeMe.hpp"

#include <utility>
#include <iostream>

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void) other;
}

PmergeMe::~PmergeMe() { }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return *this;
}

void PmergeMe::sort(std::vector<int> v)
{
	bool isOdd = v.size() % 2;
	size_t mid = v.size() / 2;

	std::vector<std::pair<int, int> > tuples;
	for (size_t i = 0; i < mid; i++)
		tuples.push_back(std::pair<int, int>(v[i], v[i + mid]));
	std::cout << "isodd " << isOdd << std::endl;
	if (isOdd)
		tuples.push_back(std::pair<int, int>(v[v.size() - 1], 0));
	
	for (std::vector<std::pair<int, int> >::iterator it = tuples.begin()
		; it != tuples.end(); it++)
	{
		if (it->first > it->second) //! check with last one when odd
			std::swap(it->first, it->second);
	}

	for (size_t i = 0; i < tuples.size(); i++)
		std::cout << tuples[i].first << " " << tuples[i].second << std::endl;
}
