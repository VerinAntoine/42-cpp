#include "Contact.h"
#include "Phonebook.h"
#include <string>
#include <iostream>
#include <stdlib.h>

static bool is_equals(std::string &a, std::string b)
{
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++)
		if (std::tolower(a[i]) != std::tolower(b[i]))
			return false;
	return true;
}

static bool is_valid(const std::string &str)
{
	if (str.empty())
	{
		std::cerr << "Input cannot be empty!" << std::endl;
		return false;
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalnum(str[i]))
		{
			std::cerr << "Input should be alnum only!" << std::endl;
			return false;
		}
	}
	return true;
}

static std::string get_input(const std::string &name)
{
	std::string str;
	do {
		if (std::cin.eof())
			break;
		std::cout << name << ": ";
		getline(std::cin, str);
	} while (!is_valid(str));
	return str;
}

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	Phonebook phonebook = Phonebook();
	int count = 0;
	std::string input;
	do {
		std::cout << "input: ";
		getline(std::cin, input);
		if (is_equals(input, "add"))
		{
			phonebook.setContact(new Contact(
				get_input("first name"),
				get_input("last name"),
				get_input("nickname"),
				get_input("phone"),
				get_input("secret")
			), count++);
			if (count >= 8)
				count = 0;
		}
		else if (is_equals(input, "search"))
		{
			std::string index;
			phonebook.print();
			std::cout << "index: ";
			getline(std::cin, index);
			int ind = atoi(index.c_str());
			if (ind < 1 || ind > 8 || phonebook.getContact(ind - 1) == NULL)
				std::cerr << "Could'nt find contact" << std::endl;
			else
				phonebook.getContact(ind - 1)->print();
		}
	} while (!(is_equals(input, "exit") || std::cin.eof()));
	if (std::cin.eof())
			std::cout << std::endl;
	return 0;
}
