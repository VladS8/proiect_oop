#ifndef DISPLAYELEVI_H
#define DISPLAYELEVI_H

#include <QLabel>
#include "Observer.h"

class DisplayElevi : public Observer {
private:
    QLabel *label; // QLabel-ul de actualizat

public:
    explicit DisplayElevi(QLabel *labelWidget) : label(labelWidget) {}
    void update(const QString &data) override {
        label->setText(data);
    }
};

#endif // DISPLAYELEVI_H