#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSqlQuery>
#include <QHBoxLayout>

#include "Subject.h"

/**
 * @class RegisterWindow
 *
 * @brief The RegisterWindow class provides a graphical interface for user registration.
 *
 * The RegisterWindow class represents a window containing all necessary
 * fields, buttons, and logic to facilitate user registration.
 * It serves as a bridge between the user interface and the back-end
 * components by validating user inputs and passing registration data.
 *
 * This class typically handles input fields such as username, password,
 * email, and other optional user information required during registration.
 * It may also include error handling for invalid inputs or failed operations.
 *
 * Responsibilities include:
 * - Rendering and initializing the registration UI components.
 * - Collecting and validating user input during registration.
 * - Submitting registration data to the backend or associated logic.
 * - Displaying error messages or success feedback to the user.
 *
 * Ensure to connect this class appropriately with event handlers and
 * backend services for the registration management to operate correctly.
 */

class RegisterWindow : public QMainWindow, public Subject{
    Q_OBJECT

private:
    QLineEdit *m_emailLineEdit_reg;
    QLineEdit *m_passwordLineEdit_reg;
    QLineEdit *m_numarmatricolLineEdit_reg;
    QPushButton *m_createAccountButton;
    QLabel *m_resultLabel_reg;
    QPushButton *m_gotologinButton;
    QPushButton *m_togglePasswordButton_reg;
    QHBoxLayout *passwordLayout_reg;

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow() override;

    private slots:
        void onPushButtonClicked() const;
};





#endif //REGISTERWINDOW_H
