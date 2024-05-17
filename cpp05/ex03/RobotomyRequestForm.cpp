#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm("RobotomyRequestForm", 72, 45), target(other.target)
{ }

RobotomyRequestForm::~RobotomyRequestForm()
{ }

void RobotomyRequestForm::do_execute(const Bureaucrat &bureaucrat) const
{
	(void) bureaucrat;
	srand((unsigned) time(NULL));
    if (!(rand() % 2))
        std::cout << target << " has been robotomized\n";
    else
        std::cout << "Robotomy has failed\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->target = other.target;
	AForm::operator=(other);
	return *this;
}
