#include "../headers/RegisterWindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

#include "../headers/LoginWindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800, 500);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

//*******************************************************************
    layout->addSpacerItem(new QSpacerItem(0, 130));
//-------------------------------------------------------------------
    m_emailLineEdit_reg = new QLineEdit(this);
    m_emailLineEdit_reg->setPlaceholderText("Adauga email");
    m_emailLineEdit_reg->setFixedWidth(200);
    m_emailLineEdit_reg->setFixedHeight(30);
    layout->addWidget(m_emailLineEdit_reg, 0, Qt::AlignHCenter);
//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 5));
//-------------------------------------------------------------------
    passwordLayout_reg = new QHBoxLayout();
    passwordLayout_reg->setContentsMargins(0, 0, 0, 0);
    passwordLayout_reg->setSpacing(5);
    passwordLayout_reg->addSpacerItem(new QSpacerItem(290, 0));
    m_passwordLineEdit_reg = new QLineEdit(this);
    m_passwordLineEdit_reg->setPlaceholderText("Adauga parola");
    m_passwordLineEdit_reg->setFixedWidth(200);
    m_passwordLineEdit_reg->setFixedHeight(30);
    m_passwordLineEdit_reg->setEchoMode(QLineEdit::Password);

    m_togglePasswordButton_reg = new QPushButton("👀", this);
    m_togglePasswordButton_reg->setFixedWidth(30);
    m_togglePasswordButton_reg->setFixedHeight(30);
    m_togglePasswordButton_reg->setStyleSheet("font-size: 13px;");
    m_togglePasswordButton_reg->setContentsMargins(-10, 0, 0, 0);
    passwordLayout_reg->addWidget(m_passwordLineEdit_reg, -100, Qt::AlignLeft);
    passwordLayout_reg->addWidget(m_togglePasswordButton_reg, 50, Qt::AlignLeft);
    layout->addLayout(passwordLayout_reg);

    connect(m_togglePasswordButton_reg, &QPushButton::pressed, this, [this]() {
    m_passwordLineEdit_reg->setEchoMode(QLineEdit::Normal);
});

    connect(m_togglePasswordButton_reg, &QPushButton::released, this, [this]() {
    m_passwordLineEdit_reg->setEchoMode(QLineEdit::Password);
});
//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 5));
//-------------------------------------------------------------------
    m_numarmatricolLineEdit_reg = new QLineEdit(this);
    m_numarmatricolLineEdit_reg->setPlaceholderText("Adauga numarul matricol");
    m_numarmatricolLineEdit_reg->setFixedWidth(200);
    m_numarmatricolLineEdit_reg->setFixedHeight(30);
    layout->addWidget(m_numarmatricolLineEdit_reg, 0, Qt::AlignHCenter);

//-------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 25));
//-------------------------------------------------------------------
    m_createAccountButton = new QPushButton("Creeaza cont", this);
    m_createAccountButton->setFixedWidth(250);
    m_createAccountButton->setFixedHeight(50);
    m_createAccountButton->setStyleSheet("font-size: 20px; font-weight: bold;");
    layout->addWidget(m_createAccountButton, 0, Qt::AlignHCenter);
//-------------------------------------------------------------------

//-------------------------------------------------------------------
    m_gotologinButton = new QPushButton("Inapoi la pagina de logare", this);
    m_gotologinButton->setFixedWidth(200);
    m_gotologinButton->setFixedHeight(40);
    m_gotologinButton->setStyleSheet("font-size: 12px; font-weight: bold;");
    layout->addWidget(m_gotologinButton);
//*******************************************************************

    connect(m_createAccountButton, &QPushButton::clicked, this, &RegisterWindow::onPushButtonClicked);

    connect(m_gotologinButton, &QPushButton::clicked, this, [this]()
        {
            LoginWindow *loginWindow = new LoginWindow(this);
            loginWindow->show();
            this->close();
        });

}

void RegisterWindow::onPushButtonClicked() const {

    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("C:/Users/Vlad/Desktop/bazadedate1/proiect_oop_bun3/bd/test.db");

    const QString email = m_emailLineEdit_reg->text();
    const QString password = m_passwordLineEdit_reg->text();
    const QString nr_matricol = m_numarmatricolLineEdit_reg->text();

    if (sqlitedb.open()) {
        QSqlQuery query(sqlitedb);

        query.prepare("SELECT * FROM login_credential WHERE EMAIL = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next()) {
            m_resultLabel_reg->setText("Email already registered.");
        } else {
            query.prepare("SELECT * FROM login_credential WHERE NR_MATRICOL_ELEV = :nr_matricol");
            query.bindValue(":nr_matricol", nr_matricol);

            if (query.exec() && query.next()) {
                m_resultLabel_reg->setText("This student ID already has an associated email.");
            } else {
                query.prepare("INSERT INTO login_credential (EMAIL, PASSWORD, NR_MATRICOL_ELEV) VALUES (:email, :password, :nr_matricol)");
                query.bindValue(":email", email);
                query.bindValue(":password", password);
                query.bindValue(":nr_matricol", nr_matricol);

                if (query.exec()) {
                    m_resultLabel_reg->setText("Account successfully created!");
                } else {
                    m_resultLabel_reg->setText("Failed to create account.");
                }
            }
        }
    } else {
        m_resultLabel_reg->setText("Database connection failed!");
    }

    sqlitedb.close();
}


RegisterWindow::~RegisterWindow()= default;