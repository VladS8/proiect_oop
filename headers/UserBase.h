#ifndef USERBASE_H
#define USERBASE_H

#include <string>
/**
 * @class UserBase
 * @brief Abstract base class for representing a generic user.
 *
 * This class provides a foundation for representing and handling different types
 * of users. It serves as a base class that must be inherited to define specific roles.
 * The class encapsulates common attributes such as email and password and defines a
 * pure virtual function to retrieve the role of the user.
 */
class UserBase {

protected:
    std::string m_email;
    std::string m_password;

public:
    UserBase(const std::string& email, const std::string& password)
        : m_email(email), m_password(password) {}

    virtual ~UserBase() = default;

    [[nodiscard]] virtual std::string getRole() const = 0;


};

#endif //USERBASE_H

