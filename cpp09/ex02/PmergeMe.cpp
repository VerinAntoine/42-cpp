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

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < mid; i++)
		pairs.push_back(std::pair<int, int>(v[i], v[i + mid]));

	std::cout << "isodd " << isOdd << std::endl;
	std::pair<int, int> odd;
	if (isOdd)
	{
		odd.first = v[v.size() - 1];
		odd.second = -1;
	}
	v.clear();

	//!
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin()
		; it != pairs.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}

	//!
	std::cout << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;

	merge(pairs);

	//!
	std::cout << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin()
		; it != pairs.end(); it++)
	{
		if (it == pairs.begin())
			v.push_back(it->first);
		v.push_back(it->second);
	}
	
	if (isOdd)
		pairs.push_back(odd);

	//!
	std::cout << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;


}
