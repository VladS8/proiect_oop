#ifndef OBSERVER_H
#define OBSERVER_H

///

#include <QString>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const QString &data) = 0;
};

#endif //OBSERVER_H
