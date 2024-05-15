#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
: name(name), signd(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
{
	*this = other;
}

Form::~Form() { }

const std::string &Form::getName() const
{
	return this->name;
}

bool Form::isSigned() const
{
	return this->signd;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecGrade() const
{
	return this->execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	this->signd = true;
}

Form &Form::operator=(const Form &other)
{
	this->name = other.name;
	this->signd = other.signd;
	this->signGrade = other.signGrade;
	this->execGrade = other.execGrade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	return os << "name: " << obj.getName() << std::endl
		<< "signed: " << obj.isSigned() << std::endl
		<< "sign grade: " << obj.getSignGrade() << std::endl
		<< "exec grade: " << obj.getExecGrade() << std::endl;
}
