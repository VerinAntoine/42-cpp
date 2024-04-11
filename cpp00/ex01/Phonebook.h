#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iomanip>
# include <iostream>

class Phonebook {
private:
	Contact *_contacts[8];

public:
	Phonebook();
	~Phonebook();

	void setContact(Contact *contact, int i);
	Contact *getContact(int i);
	void print();
};

#endif 
