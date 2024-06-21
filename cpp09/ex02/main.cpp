#include "PmergeMe.hpp"

#include <iostream>

int do_rand() {
	return std::rand() / static_cast<float>(RAND_MAX) * 100;
}

int main(int argc, char *argv[])
{
	std::vector<int> v;
	parse(v, argv + 1, argc - 1);

	PmergeMe pm;
	pm.sort(v);

	return 0;
}
