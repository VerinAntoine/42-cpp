#ifndef FROM_HPP
# define FROM_HPP

# include <string>
# include <ostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:
	const std::string name;
	bool signd;
	const int signGrade;
	const int execGrade;

public:
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &other);
	~Form();

	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	Form &operator=(const Form &other);

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
