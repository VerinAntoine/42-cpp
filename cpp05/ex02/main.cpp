#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	{
		Bureaucrat mich("Mich", 130);
		PresidentialPardonForm form("Jean");
		mich.executeForm(form);
	}
	{
		Bureaucrat mich("Moch", 1);
		PresidentialPardonForm form("Jeanne");
		mich.executeForm(form);
	}

	Bureaucrat bob("Bob", 1);
	{
		AForm *f = new ShrubberyCreationForm("bob");
		f->execute(bob);
		delete f;
	}
	{
		AForm *f = new RobotomyRequestForm("mich");
		f->execute(bob);
		delete f;
	}
	{
		AForm *f = new PresidentialPardonForm("much");
		f->execute(bob);
		delete f;
	}
}
