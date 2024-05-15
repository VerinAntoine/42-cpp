#ifndef FROM_HPP
# define FROM_HPP

# include <string>
# include <ostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:
	std::string name;
	bool signd;
	int signGrade;
	int execGrade;

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

	class GradeTooHighException { };
	class GradeTooLowException { };

};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
