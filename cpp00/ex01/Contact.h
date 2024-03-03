#ifndef CPP_CONTACT_H
#define CPP_CONTACT_H


#include <string>

class Contact {

private:
    std::string _first_name;
    std::string _last_name;
    std::string _phone;
    std::string _secret;

public:
    Contact(const std::string &firstName, const std::string &lastName, const std::string &phone,
            const std::string &secret);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPhone() const;
    const std::string &getSecret() const;

};


#endif //CPP_CONTACT_H
