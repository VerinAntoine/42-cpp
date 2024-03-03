#include "Phonebook.h"

void Phonebook::setContact(const Contact &contact, int i) {
	_contacts[i] = contact;
}

Contact &Phonebook::getContact(int i) {
	return _contacts[i];
}

Phonebook::Phonebook() {

}
