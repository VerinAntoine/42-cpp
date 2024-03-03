#include "Contact.h"

const std::string &Contact::getFirstName() const {
    return _first_name;
}

const std::string &Contact::getLastName() const {
    return _last_name;
}

const std::string &Contact::getPhone() const {
    return _phone;
}

const std::string &Contact::getSecret() const {
    return _secret;
}

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &phone,
                 const std::string &secret) : _first_name(firstName), _last_name(lastName), _phone(phone),
                                              _secret(secret) { }
