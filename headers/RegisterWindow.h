//
// Created by Vlad on 11/26/2024.
//

#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSqlQuery>
#include <QHBoxLayout>

#include "Subject.h"


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
