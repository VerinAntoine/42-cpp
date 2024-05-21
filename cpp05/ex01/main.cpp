#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void do_form(const std::string &name, int sign, int exec)
{
	try
	{
		std::cout << "form " << name << std::endl;
		Form a(name, sign, exec);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	{
		do_form("nop", 0, 1);
		do_form("nop", 151, 1);
		do_form("nop", 1, 0);
		do_form("nop", 1, 151);
		do_form("nop", 0, 0);
		do_form("nop", 151, 151);
		do_form("yep", 1, 1);
	}
	{
		Bureaucrat bob("Bob", 2);
		Form high("High", 1, 1);
		Form ex("Ex", 2, 2);
		Form low("Low", 3, 3);

		bob.signForm(high);
		std::cout << high;
		bob.signForm(ex);
		std::cout << ex;
		bob.signForm(low);
		std::cout << low;
	}
}
