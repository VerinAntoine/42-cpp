#include "Contact.h"
#include "Phonebook.h"
#include <string>
#include <iostream>
#include <stdlib.h>

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

	Phonebook phonebook = Phonebook();
	int count = 0;
	std::string input;
	do {
		std::cout << "input: ";
		getline(std::cin, input);
		if (is_equals(input, "add"))
		{
			std::string first_name;
			std::string last_name;
			std::string nickname;
			std::string phone;
			std::string secret;
			std::cout << "first name: ";
			getline(std::cin, first_name);
			std::cout << "last name: ";
			getline(std::cin, last_name);
			std::cout << "nickname: ";
			getline(std::cin, nickname);
			std::cout << "phone: ";
			getline(std::cin, phone);
			std::cout << "secret: ";
			getline(std::cin, secret);
			phonebook.setContact(new Contact(first_name, last_name, nickname, phone, secret), count++);
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
