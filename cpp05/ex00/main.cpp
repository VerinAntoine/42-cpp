#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat a("Jean", 0);
		(void) a;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "grade too high" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "grade too low" << std::endl;
	}

	try
	{
		Bureaucrat a("Patrick", 151);
		(void) a;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "grade too high" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "grade too low" << std::endl;
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
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "grade too high" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "grade too low" << std::endl;
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
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "grade too high" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "grade too low" << std::endl;
	}
}
