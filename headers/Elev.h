#ifndef ELEV_H
#define ELEV_H
#include "UserBase.h"

class Elev : public UserBase {

private:
    int m_nrMatricol;

public:
    Elev(const std::string& email, const std::string& password, const int nrMatricol)
        : UserBase(email, password), m_nrMatricol(nrMatricol) {}

    ~Elev() override = default;

    std::string getRole() const override {
        return "Elev";
    }

};

#endif //ELEV_H
