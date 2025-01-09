#ifndef DIRIGINTE_H
#define DIRIGINTE_H

#include "UserBase.h"
#include <vector>
#include <string>
/**
 * @class Diriginte
 * @brief Class representing a Diriginte user type, derived from UserBase.
 * The Diriginte class is used to represent a user who acts as a head teacher or class coordinator (Diriginte).
 * This class extends the base functionality provided by UserBase and includes a unique identifier for the Diriginte.
 */
class Diriginte : public UserBase {

private:
    int m_idDiriginte;

public:
    Diriginte(const std::string& email, const std::string& password, int idDiriginte)
        :UserBase(email, password), m_idDiriginte(idDiriginte){}

    ~Diriginte() override = default;

    [[nodiscard]] std::string getRole() const override {
        return "Diriginte";
    }

    const std::vector<int>& getElevi() const;


};

#endif // DIRIGINTE_H