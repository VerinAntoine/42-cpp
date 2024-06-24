#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <iostream>

#include <cstdlib>

class PmergeMe
{

private:
	int parse(const std::string &param);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void sort(std::vector<int> &v);
	void sort(std::deque<int> &l);

	class InvalidInputException: std::exception
	{ };

};

template<typename T>
void join(T &pairs, T &a, T &b)
{
	pairs.clear();

	size_t i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i].second <= b[j].second)
			pairs.push_back(a[i++]);
		else
			pairs.push_back(b[j++]);
	}

	while (i < a.size())
		pairs.push_back(a[i++]);
	while (j < b.size())
		pairs.push_back(b[j++]);
}

template<typename T>
void merge(T &pairs) 
{
	if (pairs.size() > 1)
	{
		T a(pairs.begin(), pairs.begin() + pairs.size() / 2);
		merge(a);
		T b(pairs.begin() + pairs.size() / 2, pairs.end());
		merge(b);
		join(pairs, a, b);
	}
}

template<typename T>
size_t binarySearch(const T &pairs, int n)
{
	size_t start = 0;
	size_t end = pairs.size() - 1;
	while (start < end)
	{
		size_t middle = start + (end - start) / 2;
		if (pairs[middle] > n)
			end = middle;
		else
			start = middle + 1;
	}
	return start;
}

template<typename T>
void parse(T &array, char *str[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int n = std::atoi(str[i]);
		if (n < 0 || std::string(str[i]).size() > 15)
			throw PmergeMe::InvalidInputException();
		array.push_back(n);
	}
}

template<typename T>
void print(const T &array)
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

template<typename T>
T calculateGroupSizes(size_t totalElements) {
	T sizes;
	size_t i = 0, currentSize = 2, sum = 0;

	while (sum + currentSize <= totalElements) {
		sum += currentSize;
		sizes.push_back(currentSize);
		i++;
		if (i < 2)
			currentSize = sizes[i - 1];
		else
			currentSize = sizes[i - 2] * 2 + sizes[i - 1];
	}

	if (sum < totalElements) {
		sizes.push_back(totalElements - sum);
	}

	return sizes;
}

#endif
