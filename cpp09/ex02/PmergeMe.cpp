#include "PmergeMe.hpp"

#include <cmath>
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

void PmergeMe::sort(std::vector<int> &v)
{
	bool isOdd = v.size() % 2;

	std::vector<std::pair<int, int> > pairs;
	std::pair<int, int> odd;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (isOdd && v.size() == i + 1)
			odd = (std::pair<int, int>(v[i], -1));
		else
			pairs.push_back(std::pair<int, int>(v[i], v[i + 1]));
	}

	v.clear();

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin()
		; it != pairs.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}

	merge(pairs);

	v.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); i++)
		v.push_back(pairs[i].second);
	pairs.erase(pairs.begin());
	if (isOdd)
		pairs.push_back(odd);
	
	std::vector<size_t> groupSizes = calculateGroupSizes<std::vector<size_t> >(pairs.size());

	size_t iterOdd = 0;
	for (size_t i = 0; i < groupSizes.size(); i++)
	{
		for (size_t j = groupSizes[i]; j > 0; j--)
		{
			int x = pairs[iterOdd + j - 1].first;
			std::vector<int>::iterator it = v.begin();
			while (it < v.end() - 1 && x > *it)
				it++;
			v.insert(it, x);
		}	
		iterOdd += groupSizes[i];
	}
}

void PmergeMe::sort(std::deque<int> &l)
{
	bool isOdd = l.size() % 2;

	std::deque<std::pair<int, int> > pairs;
	std::pair<int, int> odd;
	for (size_t i = 0; i < l.size(); i += 2)
	{
		if (isOdd && l.size() == i + 1)
			odd = (std::pair<int, int>(l.at(i), -1));
		else
			pairs.push_back(std::pair<int, int>(l[i], l[i + 1]));
	}

	l.clear();

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin()
		; it != pairs.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}

	merge(pairs);

	l.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); i++)
		l.push_back(pairs[i].second);
	pairs.erase(pairs.begin());
	if (isOdd)
		pairs.push_back(odd);
	
	std::deque<size_t> groupSizes = calculateGroupSizes<std::deque<size_t> >(pairs.size());

	size_t iterOdd = 0;
	for (size_t i = 0; i < groupSizes.size(); i++)
	{
		for (size_t j = groupSizes[i]; j > 0; j--)
		{
			int x = pairs[iterOdd + j - 1].first;
			std::deque<int>::iterator it = l.begin();
			while (it < l.end() - 1 && x > *it)
				it++;
			l.insert(it, x);
		}	
		iterOdd += groupSizes[i];
	}
}
