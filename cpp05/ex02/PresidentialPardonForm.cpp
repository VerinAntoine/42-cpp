#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm("PresidentialPardonForm", 25, 5), target(other.target)
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }

void PresidentialPardonForm::do_execute(const Bureaucrat &bureaucrat) const
{
	(void) bureaucrat;
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->target = other.target;
	AForm::operator=(other);
	return *this;
}
