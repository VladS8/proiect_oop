#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObserver(const QString &data) const;
};

#endif // SUBJECT_H