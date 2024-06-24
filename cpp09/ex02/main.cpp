#include "PmergeMe.hpp"

#include <iostream>
#include <sys/time.h>

int do_rand() {
	return std::rand() / static_cast<float>(RAND_MAX) * 100;
}

time_t gettime(struct timeval start, struct timeval end)
{
	return (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}

int main(int argc, char *argv[])
{
	if (argc <= 2)
	{
		std::cout << argv[0] << " <values>" << std::endl;
		return 1;
	}

	std::vector<int> v;
	std::deque<int> d;
	parse(v, argv + 1, argc - 1);
	parse(d, argv + 1, argc - 1);
	std::cout << "=> before sort" << std::endl;
	std::cout << "vector: ";
	print(v);
	std::cout << "deque: ";
	print(d);

	PmergeMe pm;

	struct timeval start, end;
	gettimeofday(&start, NULL);
	pm.sort(v);
	gettimeofday(&end, NULL);
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << gettime(start, end) << " us" << std::endl;

	gettimeofday(&start, NULL);
	pm.sort(d);
	gettimeofday(&end, NULL);
	std::cout << "Time to process a range of " << v.size() << " elements with std::deque : " << gettime(start, end) << " us" << std::endl;

	std::cout << "=> after sort" << std::endl;
	std::cout << "vector: ";
	print(v);
	std::cout << "deque: ";
	print(d);

	return 0;
}
