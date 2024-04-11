#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class Contact {

private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone;
    std::string _secret;

public:
    Contact(const std::string &firstName, const std::string &lastName,
            const std::string &nickname, const std::string &phone,
            const std::string &secret);
    ~Contact();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhone() const;
    const std::string &getSecret() const;
    void print() const;
};

#endif
