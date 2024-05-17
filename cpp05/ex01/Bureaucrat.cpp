#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: name(name), grade(grade)	
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat() { }

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because his grade is to low!" << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->name = other.name;
	this->grade = other.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}
