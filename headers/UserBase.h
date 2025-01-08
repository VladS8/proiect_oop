#ifndef USERBASE_H
#define USERBASE_H

#include <string>

class UserBase {

protected:
    std::string m_email;
    std::string m_password;

public:
    UserBase(const std::string& email, const std::string& password)
        : m_email(email), m_password(password) {}

    virtual ~UserBase() = default;

    virtual std::string getRole() const = 0;


};

#endif //USERBASE_H

