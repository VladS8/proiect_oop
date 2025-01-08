#ifndef DIRIGINTE_H
#define DIRIGINTE_H

#include "UserBase.h"
#include <vector>
#include <string>

class Diriginte : public UserBase {

private:
    int m_idDiriginte;

public:
    Diriginte(const std::string& email, const std::string& password, int idDiriginte)
        :UserBase(email, password), m_idDiriginte(idDiriginte){}

    ~Diriginte() override = default;

    std::string getRole() const override {
        return "Diriginte";
    }

    const std::vector<int>& getElevi() const;


};

#endif // DIRIGINTE_H