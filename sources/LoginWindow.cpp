#include "../headers/LoginWindow.h"
#include "../headers/RegisterWindow.h"
#include "../headers/PanelWindowElev.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>



LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800, 500);

    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto *layout = new QVBoxLayout(centralWidget);

//*******************************************************************
    layout->addSpacerItem(new QSpacerItem(0, 130));
//-------------------------------------------------------------------
    m_emailLineEdit = new QLineEdit(this);
    m_emailLineEdit->setPlaceholderText("Email");
    m_emailLineEdit->setFixedWidth(200);
    m_emailLineEdit->setFixedHeight(30);
    layout->addWidget(m_emailLineEdit, 0, Qt::AlignHCenter);
//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 5));
//-------------------------------------------------------------------
    passwordLayout = new QHBoxLayout();
    passwordLayout->setContentsMargins(0, 0, 0, 0);
    passwordLayout->setSpacing(5);
    passwordLayout->addSpacerItem(new QSpacerItem(290, 0));
    m_passwordLineEdit = new QLineEdit(this);
    m_passwordLineEdit->setPlaceholderText("Parola");
    m_passwordLineEdit->setFixedWidth(200);
    m_passwordLineEdit->setFixedHeight(30);
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);

    m_togglePasswordButton = new QPushButton("👀", this);
    m_togglePasswordButton->setFixedWidth(30);
    m_togglePasswordButton->setFixedHeight(30);
    m_togglePasswordButton->setStyleSheet("font-size: 13px;");
    m_togglePasswordButton->setContentsMargins(-10, 0, 0, 0);
    passwordLayout->addWidget(m_passwordLineEdit, -100, Qt::AlignLeft);
    passwordLayout->addWidget(m_togglePasswordButton, 50, Qt::AlignLeft);
    layout->addLayout(passwordLayout);

    connect(m_togglePasswordButton, &QPushButton::pressed, this, [this]() {
    m_passwordLineEdit->setEchoMode(QLineEdit::Normal);
});

    connect(m_togglePasswordButton, &QPushButton::released, this, [this]() {
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);
});
//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 20));
//-------------------------------------------------------------------
    m_loginButton = new QPushButton("Intra in cont", this);
    m_loginButton->setFixedWidth(150);
    m_loginButton->setFixedHeight(50);
    m_loginButton->setStyleSheet("font-size: 20px; font-weight: bold;");
    layout->addWidget(m_loginButton, 0, Qt::AlignHCenter);

//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 0));
//-------------------------------------------------------------------
    m_textLabel = new QLabel("Nu ai deja un cont?",this);
    layout->addWidget(m_textLabel, 0, Qt::AlignHCenter);
//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, -40));
//-------------------------------------------------------------------
    m_gotoregisterButton = new QPushButton("Creeaza un cont", this);
    m_gotoregisterButton->setFixedWidth(150);
    m_gotoregisterButton->setFixedHeight(40);
    m_gotoregisterButton->setStyleSheet("font-size: 15px; font-weight: bold;");
    layout->addWidget(m_gotoregisterButton, 0, Qt::AlignHCenter);
//-------------------------------------------------------------------
    m_resultLabel = new QLabel(this);
    layout->addWidget(m_resultLabel);
//*******************************************************************


    connect(m_loginButton, &QPushButton::clicked, this, &LoginWindow::onPushButtonClicked);

    connect(m_gotoregisterButton, &QPushButton::clicked, this, [this]() {
        auto *registerWindow = new RegisterWindow(this);
        registerWindow->show();
        this->hide();
});


}


void LoginWindow::onPushButtonClicked() {

    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("C:/Users/Vlad/Desktop/bazadedate1/proiect_oop_bun3/bd/test.db");

    const QString email = m_emailLineEdit->text();
    const QString password = m_passwordLineEdit->text();

    if (sqlitedb.open()) {
        QSqlQuery query(sqlitedb);


        query.prepare(
            "SELECT elev.PRENUME, clasa.NUME "
            "FROM login_credential, clasa "
            "JOIN elev ON login_credential.NR_MATRICOL_ELEV = elev.NR_MATRICOL "
            "WHERE login_credential.EMAIL = :email AND login_credential.PASSWORD = :password AND elev.ID_CLASA = clasa.ID"
        );



        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (query.exec()) {
            if (query.next()) {
                QString numeElev = query.value("elev.PRENUME").toString();
                QString clasaElev = query.value("clasa.NUME").toString();
                auto *panel_window_elev = new PanelWindowElev(this, numeElev, clasaElev);
                panel_window_elev->show();
                this->hide();

            } else {
                m_resultLabel->setText("Invalid email or password.");
            }
        } else {
            m_resultLabel->setText("Login failed (database error).");
        }
    } else {
        m_resultLabel->setText("Connection failed!");
    }

    sqlitedb.close();
}



LoginWindow::~LoginWindow()= default;