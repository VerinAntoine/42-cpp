#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void ShrubberyCreationForm::do_execute(const Bureaucrat &bureaucrat) const
{
	(void) bureaucrat;
	std::ofstream os((target + "_shrubbery").c_str());
	if (!os.is_open())
	{
		std::cout << "file error" << std::endl;
		return ;
	}
	os << TREE;
	os.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->target = other.target;
	AForm::operator=(other);
	return *this;
}
