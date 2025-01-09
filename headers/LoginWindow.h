#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <memory>

#include "Observer.h"
/**
 * @class LoginWindow
 * @brief Represents the login interface in a graphical user interface application.
 *
 * The LoginWindow class is responsible for displaying a window
 * where users can input their credentials (e.g., username and password)
 * to access the application. It includes input fields for the user's credentials,
 * buttons to submit or cancel the login process,
 * and any error messages related to failed login attempts.
 *
 * The class handles the interaction between the user and the application
 * during the login process, such as validating user input,
 * authenticating credentials, and displaying appropriate feedback.
 *
 * Typical features include:
 * - Retrieving and validating user credentials.
 * - Providing a graphical form for login-related input.
 * - Handling events such as clicks on the login or cancel buttons.
 * - Displaying authentication errors or success messages.
 *
 * This class interacts closely with other components,
 * such as authentication services, to ensure secure and seamless login procedures.
 */
class LoginWindow final : public QMainWindow, public Observer
{
    Q_OBJECT

private:
    std::unique_ptr<QPushButton> m_loginButton;
    std::unique_ptr<QLineEdit> m_emailLineEdit;
    std::unique_ptr<QLineEdit> m_passwordLineEdit;
    std::unique_ptr<QLabel> m_resultLabel;
    std::unique_ptr<QLabel> m_textLabel;
    std::unique_ptr<QPushButton> m_gotoregisterButton;
    std::unique_ptr<QPushButton> m_togglePasswordButton;
    std::unique_ptr<QHBoxLayout> passwordLayout;

public:

    explicit LoginWindow(QWidget *parent = nullptr);
    void update(const QString &data) override;
    ~LoginWindow() override;

    private slots:
        void onPushButtonClicked();


};

#endif // LOGINWINDOW_H