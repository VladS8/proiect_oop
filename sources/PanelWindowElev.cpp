#include "../headers/PanelWindowElev.h"
#include "../headers/LoginWindow.h"
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QWidget>
#include <QMessageBox>


PanelWindowElev::PanelWindowElev(QWidget *parent, const QString &numeElev, const QString &clasaElev)
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

    m_testLabel2 = new QLabel("test", this);
    m_testLabel2->setFixedWidth(120);
    m_testLabel2->setFixedHeight(80);
    m_testLabel2->setAlignment(Qt::AlignCenter);
    m_testLabel2->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_testLabel2, 0, Qt::AlignRight | Qt::AlignCenter);

    m_testLabel = new QLabel(this);
    m_testLabel->setText(QString("Clasa: \n %1").arg(clasaElev));
    m_testLabel->setFixedWidth(120);
    m_testLabel->setFixedHeight(80);
    m_testLabel->setAlignment(Qt::AlignCenter);
    m_testLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addSpacerItem(new QSpacerItem(-300, 0));
    m_topLayout->addWidget(m_testLabel, 0, Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(-300, 0));

    m_welcomeMessage = new QLabel(this);
    m_welcomeMessage->setText(QString("Bine ai venit \n %1!").arg(numeElev));
    m_welcomeMessage->setFixedWidth(120);
    m_welcomeMessage->setFixedHeight(80);
    m_welcomeMessage->setAlignment(Qt::AlignCenter);
    m_welcomeMessage->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_welcomeMessage, 0, Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(25, 0));

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

    /*m_showGradesButton = new QPushButton("Afișează note", this);
    m_showGradesButton->setFixedWidth(100);
    m_showGradesButton->setFixedHeight(50);
    m_showGradesButton->setStyleSheet("border: 1px solid black;");
    m_leftLayout->addWidget(m_showGradesButton, 0, Qt::AlignTop | Qt::AlignCenter);*/

    // Connect showGradesButton to the slot
    connect(m_showGradesButton, &QPushButton::clicked, this, &PanelWindowElev::showGradesOnButtonClicked);

    // ICON FRAME
    m_iconWidget = new QFrame();
    m_iconLayout = new QVBoxLayout(m_iconWidget);
    m_iconWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_iconWidget->setLineWidth(0);
    m_iconWidget->setFixedWidth(130);
    m_iconWidget->setFixedHeight(130);

    m_icon = new QLabel();
    m_icon->setText("📖");
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

    m_indexLabel = new QLabel("Index View");
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

/*template <typename T>
T calculateAverage(const std::vector<T>& values) {
    if (values.empty()) {
        throw std::invalid_argument("Nu are note");
    }
    T sum = std::accumulate(values.begin(), values.end(), static_cast<T>(0));
    return sum / static_cast<T>(values.size());
}*/

void PanelWindowElev::showGradesOnButtonClicked()
{
   try {
       QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE", "grades_connection");
       sqlitedb.setDatabaseName("C:/Users/Vlad/Desktop/bazadedate1/proiect_oop_bun3/bd/test.db");

       if (!sqlitedb.open()) {
           throw std::runtime_error("Eroare la deschiderea bazei de date!");
       }


           QSqlQuery query(sqlitedb);
           query.prepare(R"(
               SELECT
                   nota.VAL, materie.NUME
               FROM
                   materie
               JOIN
                   nota ON materie.id = nota.id_materie
           )");

           if (!query.exec()) {
               throw std::runtime_error(query.lastError().text().toStdString());
           }

           QString grades;
           while (query.next()) {
               QString materie = query.value("materie.NUME").toString();
               QString nota = query.value("nota.VAL").toString();
               grades += QString("%1: %2\n").arg(materie, nota);
           }

           if (grades.isEmpty()) {
               grades = "Nu s-au găsit note pentru acest elev.";
           }
       m_indexLabel->setText(grades);


       sqlitedb.close();
   } catch (const std::exception &ex) {
       QMessageBox::critical(this, "Eroare", QString("A apărut o eroare: %1").arg(ex.what()));
   } catch (...) {
       QMessageBox::critical(this, "Eroare", "A apărut o eroare necunoscută.");
   }
}



PanelWindowElev::~PanelWindowElev() = default;