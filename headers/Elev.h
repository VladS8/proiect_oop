#ifndef ELEV_H
#define ELEV_H
#include "UserBase.h"
/**
 * @class Elev
 * @brief Represents a student user in the system.
 *
 * The Elev class is a derived class of UserBase, specifically designed to represent
 * a student with an associated matriculation number. It extends the functionality
 * of the UserBase class by specifying the role as "Elev" and storing an additional
 * field, m_nrMatricol, which identifies the student.
 */
class Elev : public UserBase {

private:
    int m_nrMatricol;

public:
    Elev(const std::string& email, const std::string& password, const int nrMatricol)
        : UserBase(email, password), m_nrMatricol(nrMatricol) {}

    ~Elev() override = default;

    [[nodiscard]] std::string getRole() const override {
        return "Elev";
    }

};

#endif //ELEV_H
