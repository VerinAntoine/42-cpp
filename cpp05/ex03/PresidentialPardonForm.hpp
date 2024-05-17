#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{

private:
	std::string target;

	void do_execute(const Bureaucrat &bureaucrat) const;

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

};

#endif
