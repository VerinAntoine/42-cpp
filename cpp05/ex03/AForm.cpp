#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
: name(name), signd(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
{
	*this = other;
}

AForm::~AForm() { }

const std::string &AForm::getName() const
{
	return this->name;
}

bool AForm::isSigned() const
{
	return this->signd;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecGrade() const
{
	return this->execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	this->signd = true;
}

void AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	this->do_execute(bureaucrat);
}

AForm &AForm::operator=(const AForm &other)
{
	this->name = other.name;
	this->signd = other.signd;
	this->signGrade = other.signGrade;
	this->execGrade = other.execGrade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	return os << "name: " << obj.getName() << std::endl
		<< "signed: " << obj.isSigned() << std::endl
		<< "sign grade: " << obj.getSignGrade() << std::endl
		<< "exec grade: " << obj.getExecGrade() << std::endl;
}
