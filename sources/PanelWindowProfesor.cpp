#include "../headers/PanelWindowProfesor.h"
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlError>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSqlQuery>
#include <QString>
#include <QWidget>

PanelWindowProfesor::PanelWindowProfesor(QWidget *parent, const QString &numeProfesor, const QString &materieProfesor)
    : QMainWindow(parent)
{
    setFixedSize(1200, 700);

    // MAIN WIDGET
    mainWidget = new QWidget(this);
    mainLayout = new QGridLayout(mainWidget);

    // TOP FRAME
    m_topWidget = new QFrame();
    m_topLayout = new QHBoxLayout(m_topWidget);
    m_topWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_topWidget->setLineWidth(0);
    m_topWidget->setFixedWidth(1050);
    m_topWidget->setFixedHeight(140);

    m_testLabel2 = new QLabel("Informatii Profesor", this);
    m_testLabel2->setFixedWidth(120);
    m_testLabel2->setFixedHeight(80);
    m_testLabel2->setAlignment(Qt::AlignCenter);
    m_testLabel2->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_testLabel2, 0, Qt::AlignRight | Qt::AlignCenter);

    m_testLabel = new QLabel(this);
    m_testLabel->setText(QString("Clasa: \n %1").arg(materieProfesor));
    m_testLabel->setFixedWidth(120);
    m_testLabel->setFixedHeight(80);
    m_testLabel->setAlignment(Qt::AlignCenter);
    m_testLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addSpacerItem(new QSpacerItem(0, 0));
    m_topLayout->addWidget(m_testLabel, 0, Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(0, 0));

    m_welcomeMessage = new QLabel(this);
    m_welcomeMessage->setText(QString("Bine ai venit, \n %1!").arg(numeProfesor));
    m_welcomeMessage->setFixedWidth(120);
    m_welcomeMessage->setFixedHeight(80);
    m_welcomeMessage->setAlignment(Qt::AlignCenter);
    m_welcomeMessage->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_welcomeMessage, 0, Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(25, 0));

    m_showStudentsButton = new QPushButton("Vezi elevii", this);
    m_showStudentsButton->setFixedWidth(80);
    m_showStudentsButton->setFixedHeight(50);
    m_showStudentsButton->setStyleSheet("border: 1px solid black;");
    m_leftLayout->addSpacerItem(new QSpacerItem(0, 25));
    m_leftLayout->addWidget(m_showStudentsButton, 0, Qt::AlignTop | Qt::AlignCenter);

    // LEFT FRAME

    m_leftWidget = new QFrame();
    m_leftLayout = new QVBoxLayout(m_leftWidget);
    m_leftWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_leftWidget->setLineWidth(0);
    m_leftWidget->setFixedWidth(140);
    m_leftWidget->setFixedHeight(550);

    m_showGradesButton = new QPushButton("Vezi notele", this);
    m_showGradesButton->setFixedWidth(80);
    m_showGradesButton->setFixedHeight(50);
    m_showGradesButton->setStyleSheet("border: 1px solid black;");
    m_leftLayout->addSpacerItem(new QSpacerItem(0, 25));
    m_leftLayout->addWidget(m_showGradesButton, 0, Qt::AlignTop | Qt::AlignCenter);

    m_manageStudentsButton = new QPushButton("Gestioneaza elevii", this);
    m_manageStudentsButton->setFixedWidth(100);
    m_manageStudentsButton->setFixedHeight(50);
    m_manageStudentsButton->setStyleSheet("border: 1px solid black;");
    m_leftLayout->addWidget(m_manageStudentsButton, 0, Qt::AlignTop | Qt::AlignCenter);


    connect(m_showStudentsButton, &QPushButton::clicked, this, [this, materieProfesor]() {
        showStudentsOnPushButtonClicked(materieProfesor);
    });


    // ICON FRAME
    m_iconWidget = new QFrame();
    m_iconLayout = new QVBoxLayout(m_iconWidget);
    m_iconWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_iconWidget->setLineWidth(0);
    m_iconWidget->setFixedWidth(130);
    m_iconWidget->setFixedHeight(130);

    m_icon = new QLabel();
    m_icon->setText("🎓");
    m_icon->setFixedWidth(120);
    m_icon->setFixedHeight(120);
    m_icon->setAlignment(Qt::AlignCenter);
    m_icon->setStyleSheet("font-size: 50px; border: 1px solid black;");
    m_iconLayout->addWidget(m_icon);

    // MAIN FRAME
    m_indexWidget = new QStackedWidget();
    m_indexWidget->setStyleSheet("border: 1px solid black;");
    m_indexWidget->setFixedWidth(1040);
    m_indexWidget->setFixedHeight(540);

    m_indexLabel = new QLabel("Bun venit în tabloul Profesorului!");
    m_indexLabel->setAlignment(Qt::AlignCenter);
    m_indexLabel->setStyleSheet("font-size: 20px;");
    m_indexWidget->addWidget(m_indexLabel);
    m_indexWidget->setCurrentIndex(0);

    // Add widgets to the main layout
    mainLayout->addWidget(m_topWidget, 0, 1, 1, 2);
    mainLayout->addWidget(m_leftWidget, 1, 0);
    mainLayout->addWidget(m_iconWidget, 0, 0);
    mainLayout->addWidget(m_indexWidget, 1, 1, 1, 1);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void PanelWindowProfesor::showStudentsOnPushButtonClicked(const QString& idDiriginte) {
    try {
        QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE", "grades_connection");
        sqlitedb.setDatabaseName("C:/Users/Vlad/Desktop/bazadedate1/proiect_oop_bun3/bd/test.db");

        if (!sqlitedb.open()) {
            qDebug() << "Eroare la deschiderea bazei de date:" << sqlitedb.lastError().text();
            throw std::runtime_error("Eroare la deschiderea bazei de date!");
        }
        qDebug() << "ID-ul diriginte utilizat este:" << idDiriginte;
        QSqlQuery query(sqlitedb);
        query.prepare(R"(
               SELECT
                   elev.NUME, elev.PRENUME
               FROM
                   elev
            )");
        query.bindValue(":idDiriginte", idDiriginte);
        if (!query.exec()) {
            qDebug() << "Eroare la execuția interogării:" << query.lastError().text();
            throw std::runtime_error(query.lastError().text().toStdString());
        }

        QString elevi;
        while (query.next()) {
            QString numeElev = query.value("NUME").toString();
            QString prenumeElev = query.value("PRENUME").toString();
            elevi += QString("%1 %2\n").arg(numeElev, prenumeElev);
        }


        if (elevi.isEmpty()) {
            m_indexLabel->setText("Nu există elevi în această clasă.");
        } else {
            m_indexLabel->setText(elevi);
        }

        sqlitedb.close();

    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Eroare", QString("A apărut o eroare: %1").arg(ex.what()));
    } catch (...) {
        QMessageBox::critical(this, "Eroare", "A apărut o eroare necunoscută.");
    }
}

PanelWindowProfesor::~PanelWindowProfesor() = default;