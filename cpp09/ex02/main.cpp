#include "PmergeMe.hpp"

#include <iostream>

int main()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(8);
	v.push_back(2);
	v.push_back(67);
	v.push_back(1);
	v.push_back(54);
	v.push_back(7);
	v.push_back(12);
	v.push_back(70);
	v.push_back(3);
	PmergeMe pm;
	pm.sort(v);

	return 0;
}
