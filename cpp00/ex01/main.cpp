#include "Contact.h"
#include "Phonebook.h"
#include <string>
#include <iostream>

void createContact(Contact *contact)
{
	std::string first_name;
	std::string last_name;
	std::string phone;
	std::string secret;
	getline(std::cin, first_name);
	getline(std::cin, last_name);
	getline(std::cin, phone);
	getline(std::cin, secret);
	contact.
}

bool is_equals(std::string &a, std::string b)
{
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++)
		if (std::tolower(a[i]) != std::tolower(b[i]))
			return false;
	return true;
}

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

	Phonebook phonebook;
	int count = 0;
	std::string input;
	do {
		std::cout << "input: ";
		getline(std::cin, input);
		if (is_equals(input, "add"))
		{
			phonebook.setContact(createContact(), ++count);
		}
		else if (is_equals(input, "search"))
			continue;
	} while (!(is_equals(input, "exit") || std::cin.eof()));
	if (std::cin.eof())
			std::cout << std::endl;
    return 0;
}
