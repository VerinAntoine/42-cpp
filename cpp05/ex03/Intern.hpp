#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

private:
	struct {
		std::string name;
		AForm *(Intern::*f)(const std::string &target);
	} forms[3];

	AForm *makeShrubberyCreationForm(const std::string &target);
	AForm *makeRobotomyRequestForm(const std::string &target);
	AForm *makePresidentialPardonForm(const std::string &target);

public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);

	Intern &operator=(const Intern &other);

};

#endif
