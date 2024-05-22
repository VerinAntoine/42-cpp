#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> a(5);
	a[1] = 2;

	{
		try
		{
			std::cout << a[6] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << a[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << a[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	Array<int> b(7);
	b[1] = 0;
	b[3] = 1;
	a = b;
	std::cout << a.size() << " - " << b.size() << std::endl;
	std::cout << a[1] << " " << a[3] << std::endl;

	return 0;
}
