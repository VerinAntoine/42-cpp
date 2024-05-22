#include "iter.hpp"
#include <iostream>

template<typename T>
void iter(T *array, int size, void (*f)(T))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

void print(int i)
{
	std::cout << i << std::endl;
}

int main()
{
	int i[5] = {3, 5, 2, 6, 9};
	iter(i, 5, *print);
}
