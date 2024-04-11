#include "Contact.h"

Contact::Contact(const std::string &firstName, const std::string &lastName,
                 const std::string &nickname, const std::string &phone,
                 const std::string &secret)
: _first_name(firstName), _last_name(lastName), _nickname(nickname),
    _phone(phone), _secret(secret) { }

Contact::~Contact()
{ }

const std::string &Contact::getFirstName() const {
    return _first_name;
}

const std::string &Contact::getLastName() const {
    return _last_name;
}

const std::string &Contact::getNickname() const {
    return _nickname;
}

const std::string &Contact::getPhone() const {
    return _phone;
}

const std::string &Contact::getSecret() const {
    return _secret;
}

void Contact::print() const {
    std::cout << "First name: " << _first_name << std::endl;
    std::cout << "Last name: " << _last_name << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone: " << _phone << std::endl;
    std::cout << "Secret: " << _secret << std::endl;
}
