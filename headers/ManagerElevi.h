#ifndef MANAGERELEVI_H
#define MANAGERELEVI_H
#include "Subject.h"

class ManagerElevi : public Subject {
public:
    void updateStudentList(const QString &newList) {
        notifyObserver(newList);
    }
};

#endif // MANAGERELEVI_H