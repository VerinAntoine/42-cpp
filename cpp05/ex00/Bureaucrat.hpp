#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <ostream>

class Bureaucrat
{

private:
	std::string name;
	int grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	Bureaucrat &operator=(const Bureaucrat &other);

	class GradeTooHighException
	{ };

	class GradeTooLowException
	{ };

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
