#include "header.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

Base *generate()
{
	srand((unsigned) time(NULL));
	int r = rand() % 3;

	switch(r)
	{
		case 0:
			std::cout << "got A" << std::endl;
			return new A;
		case 1:
			std::cout << "got B" << std::endl;
			return new B;
		case 2:
			std::cout << "got C" << std::endl;
			return new C;
		default:
			return NULL;
	}
}

void indentify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void indentify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) { }

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) { }

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) { }
}

int main()
{
	Base *b = generate();

	indentify(b);
	indentify(*b);

	delete b;

	// int n;
	// if (argc == 1)
	// 	n = 1;
	// else
	// 	n = atoi(argv[1]);
	
	// std::cout << "doing " << n << " times" << std::endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	Base *b = generate();
	// 	indentify(b);
	// 	indentify(*b);
	// 	delete b;
	// 	usleep(500);
	// }
	return 0;
}
