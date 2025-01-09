#ifndef DISPLAYELEVI_H
#define DISPLAYELEVI_H

#include <QLabel>
#include "Observer.h"
/**
 * @class DisplayElevi
 * @brief A class that observes updates and displays student-related data.
 *
 * The DisplayElevi class implements the Observer interface and is responsible
 * for receiving updates and displaying them on a specified QLabel widget.
 * It listens to notifications from subjects (e.g., a data manager) and updates
 * the displayed content accordingly.
 *
 * @note This class primarily operates in conjunction with an MVC (Model-View-Controller)
 *       pattern, where it serves as the observer/view component, updating the GUI
 *       based on changes in the underlying model.
 */
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