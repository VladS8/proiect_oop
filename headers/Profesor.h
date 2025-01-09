#ifndef PROFESOR_H
#define PROFESOR_H
#include "UserBase.h"
/**
 * @class Profesor
 * @brief Represents a professor in the system, inheriting properties and methods from the UserBase class.
 *
 * The Profesor class extends the UserBase class to specifically represent a professor user.
 * It includes the unique identifier for a professor and overrides the getRole method to return the role type.
 */
class Profesor : public UserBase {

private:
    int m_idProfesor;

public:
    Profesor(const std::string& email, const std::string& password, const int idProfesor)
        : UserBase(email, password), m_idProfesor(idProfesor){}

    ~Profesor() override = default;

    [[nodiscard]] std::string getRole() const override {
        return "Profesor";
    }


};

#endif //PROFESOR_H
