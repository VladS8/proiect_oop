#include "../headers/Subject.h"
#include <algorithm> // Pentru std::remove

void Subject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notifyObserver(const QString &data) const {
    for (auto observer : observers) {
        observer->update(data);
    }
}