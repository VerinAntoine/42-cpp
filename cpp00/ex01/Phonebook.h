#ifndef CPP_PHONEBOOK_H
#define CPP_PHONEBOOK_H

#include "Contact.h"

class Phonebook {
private:
	Contact _contacts[5];

public:
	Phonebook();

	void setContact(const Contact &contact, int i);
	Contact &getContact(int i);
};


#endif //CPP_PHONEBOOK_H
