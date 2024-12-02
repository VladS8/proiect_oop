    #ifndef LOGININDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSqlQuery>
#include <QHBoxLayout>

class LoginWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPushButton *m_loginButton;
    QLineEdit *m_emailLineEdit;
    QLineEdit *m_passwordLineEdit;
    QLabel *m_resultLabel;
    QLabel *m_textLabel;
    QPushButton *m_gotoregisterButton;
    QPushButton *m_togglePasswordButton;
    QHBoxLayout *passwordLayout;

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow() override;

    private slots:
        void onPushButtonClicked();

};

#endif  LOGINWINDOW_H