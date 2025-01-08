#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <memory>

#include "Observer.h"

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