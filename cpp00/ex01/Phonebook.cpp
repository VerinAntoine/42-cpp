#include "Phonebook.h"

Phonebook::Phonebook()
{
	for (int i = 0; i < 8; i++)
		_contacts[i] = NULL;
}

Phonebook::~Phonebook()
{
	for (int i = 0; i < 8; i++)
		delete _contacts[i];
}

void Phonebook::setContact(Contact *contact, int i)
{
	if (_contacts[i] != NULL)
		delete _contacts[i];
	_contacts[i] = contact;
}

Contact *Phonebook::getContact(int i) {
	return _contacts[i];
}

static void print_field(std::string field)
{
	if (field.size() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::left << field;
}

void Phonebook::print()
{
	std::cout << "index|first name|last name |nickname  |phone     " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i] != NULL)
		{
			Contact *c = _contacts[i];
			std::cout << i + 1 << "    " << "|";
			print_field(c->getFirstName());
			std::cout << "|";
			print_field(c->getLastName());
			std::cout << "|";
			print_field(c->getNickname());
			std::cout << "|";
			print_field(c->getPhone());
			std::cout << std::endl;
		}
	}
}
