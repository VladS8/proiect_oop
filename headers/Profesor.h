#ifndef PROFESOR_H
#define PROFESOR_H
#include "UserBase.h"

class Profesor : public UserBase {

private:
    int m_idProfesor;

public:
    Profesor(const std::string& email, const std::string& password, const int idProfesor)
        : UserBase(email, password), m_idProfesor(idProfesor){}

    ~Profesor() override = default;

    std::string getRole() const override {
        return "Profesor";
    }


};

#endif //PROFESOR_H
