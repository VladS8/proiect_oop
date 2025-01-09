#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
/**
 * @class Subject
 * @brief The Subject class provides a mechanism for managing a list of observers
 *        and notifying them of any changes or updates.
 *
 * The Subject class maintains a collection of observers and provides methods to
 * add, remove, and notify these observers. This class serves as the base for
 * the observer design pattern, where changes in the Subject are propagated to
 * all registered observers.
 */

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObserver(const QString &data) const;
};

#endif // SUBJECT_H