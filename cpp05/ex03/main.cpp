#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("bob", 1);
	Intern i;
	AForm *f;

	f = i.makeForm("PresidentialPardonForm", "mich");
	f->execute(b);
	delete f;
	f = i.makeForm("RobotomyRequestForm", "much");
	f->execute(b);
	delete f;
	f = i.makeForm("ShrubberyCreationForm", "moch");
	f->execute(b);
	delete f;
	try
	{
		i.makeForm("nop", "nop");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
}
