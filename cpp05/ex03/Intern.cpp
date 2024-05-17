#include "Intern.hpp"
#include <iostream>

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

Intern::Intern()
{
	forms[0].name = "PresidentialPardonForm";
	forms[0].f = &Intern::makePresidentialPardonForm;
	forms[1].name = "RobotomyRequestForm";
	forms[1].f = &Intern::makeRobotomyRequestForm;
	forms[2].name = "ShrubberyCreationForm";
	forms[2].f = &Intern::makeShrubberyCreationForm;
}

Intern::Intern(const Intern &other)
{
	(void) other;
	Intern();
}

Intern::~Intern()
{ }

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
			return (this->*forms[i].f)(target);
	}
	std::cout << "Unknown form " << name << std::endl;
	return NULL;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}
