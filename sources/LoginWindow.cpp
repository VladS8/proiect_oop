#include "../headers/LoginWindow.h"

#include <QMessageBox>
#include "../headers/RegisterWindow.h"
#include "../headers/PanelWindowElev.h"
#include "../headers/UserBase.h"
#include "../headers/Elev.h"
#include "../headers/Profesor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpacerItem>
#include <stdexcept>
#include <QString>

#include "../headers/Diriginte.h"
#include "../headers/PanelWindowDiriginte.h"
#include "../headers/PanelWindowProfesor.h"

// Constructor
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800, 500);

    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto *layout = new QVBoxLayout(centralWidget);

    // *********************************************************************
    layout->addSpacerItem(new QSpacerItem(0, 130));
    // ---------------------------------------------------------------------

    m_emailLineEdit = std::make_unique<QLineEdit>(this);
    m_emailLineEdit->setPlaceholderText("Email");
    m_emailLineEdit->setFixedWidth(200);
    m_emailLineEdit->setFixedHeight(30);
    layout->addWidget(m_emailLineEdit.get(), 0, Qt::AlignHCenter);

    // ---------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 5));
    // ---------------------------------------------------------------------

    passwordLayout = std::make_unique<QHBoxLayout>();
    passwordLayout->setContentsMargins(0, 0, 0, 0);
    passwordLayout->setSpacing(5);
    passwordLayout->addSpacerItem(new QSpacerItem(290, 0));

    m_passwordLineEdit = std::make_unique<QLineEdit>(this);
    m_passwordLineEdit->setPlaceholderText("Parola");
    m_passwordLineEdit->setFixedWidth(200);
    m_passwordLineEdit->setFixedHeight(30);
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);

    m_togglePasswordButton = std::make_unique<QPushButton>("👀", this);
    m_togglePasswordButton->setFixedWidth(30);
    m_togglePasswordButton->setFixedHeight(30);
    m_togglePasswordButton->setStyleSheet("font-size: 13px;");
    m_togglePasswordButton->setContentsMargins(-10, 0, 0, 0);

    passwordLayout->addWidget(m_passwordLineEdit.get(), -100, Qt::AlignLeft);
    passwordLayout->addWidget(m_togglePasswordButton.get(), 50, Qt::AlignLeft);
    layout->addLayout(passwordLayout.get());

    connect(m_togglePasswordButton.get(), &QPushButton::pressed, this, [this]() {
        m_passwordLineEdit->setEchoMode(QLineEdit::Normal);
    });

    connect(m_togglePasswordButton.get(), &QPushButton::released, this, [this]() {
        m_passwordLineEdit->setEchoMode(QLineEdit::Password);
    });

    // ---------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 20));
    // ---------------------------------------------------------------------

    m_loginButton = std::make_unique<QPushButton>("Intra in cont", this);
    m_loginButton->setFixedWidth(150);
    m_loginButton->setFixedHeight(50);
    m_loginButton->setStyleSheet("font-size: 21px; font-weight: bold;");
    layout->addWidget(m_loginButton.get(), 0, Qt::AlignHCenter);

    // ---------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, 0));
    // ---------------------------------------------------------------------

    m_textLabel = std::make_unique<QLabel>("Nu ai deja un cont?", this);
    layout->addWidget(m_textLabel.get(), 0, Qt::AlignHCenter);

    // ---------------------------------------------------------------------
    layout->addSpacerItem(new QSpacerItem(0, -40));
    // ---------------------------------------------------------------------

    m_gotoregisterButton = std::make_unique<QPushButton>("Creeaza un cont", this);
    m_gotoregisterButton->setFixedWidth(150);
    m_gotoregisterButton->setFixedHeight(40);
    m_gotoregisterButton->setStyleSheet("font-size: 15px; font-weight: bold;");
    layout->addWidget(m_gotoregisterButton.get(), 0, Qt::AlignHCenter);

    // ---------------------------------------------------------------------
    m_resultLabel = std::make_unique<QLabel>(this);
    layout->addWidget(m_resultLabel.get());

    // *********************************************************************

    connect(m_loginButton.get(), &QPushButton::clicked, this, &LoginWindow::onPushButtonClicked);

    connect(m_gotoregisterButton.get(), &QPushButton::clicked, this, [this]() {
        auto *registerWindow = new RegisterWindow(this);
        registerWindow->show();
        registerWindow->addObserver(this);
        //this->hide();
    });
}

void LoginWindow::onPushButtonClicked()
{
    try {
        QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
        sqlitedb.setDatabaseName("C:/Users/Vlad/Desktop/bazadedate1/proiect_oop_bun3/bd/test.db");

        if (!sqlitedb.open()) {
            throw std::runtime_error("Failed to open the database.");
        }

        const QString email = m_emailLineEdit->text();
        const QString password = m_passwordLineEdit->text();

        QSqlQuery query(sqlitedb);

        // ================= Verificări pentru Diriginte =================
        query.prepare(
            "SELECT profesor.PRENUME, clasa.NUME, clasa.ID_DIRIGINTE "
            "FROM clasa "
            "JOIN profesor ON clasa.ID_DIRIGINTE = profesor.ID "
            "WHERE profesor.EMAIL = :email AND profesor.PAROLA = :password"
        );
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (!query.exec()) {
            throw std::runtime_error("Failed to execute the query for diriginte.");
        }

        if (query.next()) {
            QString numeDiriginte = query.value("profesor.PRENUME").toString();
            QString numeClasa = query.value("clasa.NUME").toString();
            QString idDiriginte = query.value("clasa.ID_DIRIGINTE").toString();

            Diriginte diriginte(email.toStdString(), password.toStdString(), idDiriginte.toInt());

            if (const UserBase* user = &diriginte; user->getRole() == "Diriginte") {
                auto *panel_window_diriginte = new PanelWindowDiriginte(this, numeDiriginte, numeClasa, idDiriginte);
                panel_window_diriginte->show();
                this->hide();
                return;
            }
        }

        query.prepare(
            "SELECT profesor.PRENUME, materie.NUME, profesor.ID "
            "FROM profesor "
            "JOIN materie ON profesor.ID = materie.ID_PROFESOR "
            "WHERE profesor.EMAIL = :email AND profesor.PAROLA = :password"
        );
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (!query.exec()) {
            throw std::runtime_error("Failed to execute the query for professor.");
        }

        if (query.next()) {
            QString numeProfesor = query.value("profesor.PRENUME").toString();
            QString idProfesor = query.value("profesor.ID").toString();
            QString materieProfesor = query.value("materie.NUME").toString();

            const Profesor profesor(email.toStdString(), password.toStdString(), idProfesor.toInt());

            if (const UserBase* user = &profesor; user->getRole() == "Profesor") {
                auto *panel_window_profesor = new PanelWindowProfesor(this, numeProfesor, materieProfesor);
                panel_window_profesor->show();
                this->hide();
            }
        }

        query.prepare(
            "SELECT elev.PRENUME, clasa.NUME, elev.NR_MATRICOL "
            "FROM login_credential, clasa "
            "JOIN elev ON login_credential.NR_MATRICOL_ELEV = elev.NR_MATRICOL "
            "WHERE login_credential.EMAIL = :email AND login_credential.PASSWORD = :password AND elev.ID_CLASA = clasa.ID"
        );
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (!query.exec()) {
            throw std::runtime_error("Failed to execute the query for student.");
        }

        if (query.next()) {
            QString numeElev = query.value("elev.PRENUME").toString();
            QString clasaElev = query.value("clasa.NUME").toString();
            QString nrMatricolElev = query.value("elev.NR_MATRICOL").toString();

            const Elev elev(email.toStdString(), password.toStdString(), nrMatricolElev.toInt());

            if (const UserBase* user = &elev; user->getRole() == "Elev") {
                auto *panel_window_elev = new PanelWindowElev(this, numeElev, clasaElev);
                panel_window_elev->show();
                this->hide();
            }
        }

        m_resultLabel->setText("Email sau parola incorecta.");
        sqlitedb.close();
    } catch (const std::runtime_error& e) {
        m_resultLabel->setText(QString("Error: %1").arg(e.what()));
    } catch (...) {
        m_resultLabel->setText("An unknown error occurred.");
    }
}

void LoginWindow::update(const QString &data) {
    QMessageBox::information(this, "Notification", data);
    m_textLabel->setText("Contul tau a fost creat");
}

LoginWindow::~LoginWindow() = default;