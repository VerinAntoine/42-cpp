#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat a("Jean", 0);
		(void) a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Patrick", 151);
		(void) a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Bob", 2);
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Mich", 149);
		std::cout << a;
		a.decrementGrade();
		std::cout << a;
		a.decrementGrade();
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
