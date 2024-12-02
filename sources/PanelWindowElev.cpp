#include "../headers/PanelWindowElev.h"
#include "../headers/LoginWindow.h"
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSqlQuery>
#include <QString>
#include <QWidget>



PanelWindowElev::PanelWindowElev(QWidget *parent, const QString &numeElev, const QString &clasaElev)
    : QMainWindow(parent)
{
    setFixedSize(1200, 700);
//******************************************************************************************
    mainWidget = new QWidget(this);
    mainLayout = new QGridLayout(mainWidget);
//*******************************************************************************************
//TOP FRAME

    m_topWidget = new QFrame();
    m_topLayout = new QHBoxLayout(m_topWidget);
    m_topWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_topWidget->setLineWidth(0);
    m_topWidget->setFixedWidth(1050);
    m_topWidget->setFixedHeight(140);

//----------------------------------------------------------------------------------------------------------
//WIDGET3 TOP FRAME
    m_testLabel2 = new QLabel("test",this);
    m_testLabel2->setFixedWidth(120);
    m_testLabel2->setFixedHeight(80);
    m_testLabel2->setAlignment(Qt::AlignCenter);
    m_testLabel2->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_testLabel2, 0,  Qt::AlignRight | Qt::AlignCenter);

//----------------------------------------------------------------------------------------------------------
//WIDGET2 TOP FRAME
    m_testLabel = new QLabel(this);
    m_testLabel->setText(QString("Clasa: \n %1").arg(clasaElev));
    m_testLabel->setFixedWidth(120);
    m_testLabel->setFixedHeight(80);
    m_testLabel->setAlignment(Qt::AlignCenter);
    m_testLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addSpacerItem(new QSpacerItem(-300, 0));
    m_topLayout->addWidget(m_testLabel, 0,  Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(-300, 0));
//----------------------------------------------------------------------------------------------------------
//WIDGET1 TOP FRAME
    m_welcomeMessage = new QLabel(this);
    m_welcomeMessage->setText(QString("Bine ai venit \n %1!").arg(numeElev));
    m_welcomeMessage->setFixedWidth(120);
    m_welcomeMessage->setFixedHeight(80);
    m_welcomeMessage->setAlignment(Qt::AlignCenter);
    m_welcomeMessage->setStyleSheet("font-size: 18px; font-weight: bold; border: 1px solid black;");
    m_topLayout->addWidget(m_welcomeMessage, 0, Qt::AlignRight | Qt::AlignCenter);
    m_topLayout->addSpacerItem(new QSpacerItem(25, 0));


//*************************************************************************
//LEFT FRAME
    m_leftWidget = new QFrame();
    m_leftLayout = new QVBoxLayout(m_leftWidget);
    m_leftWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_leftWidget->setLineWidth(0);
    m_leftWidget->setFixedWidth(140);
    m_leftWidget->setFixedHeight(550);
//----------------------------------------------------------------------------------------------------------
//WIDGET1 LEFT FRAME
    m_Button1 = new QPushButton("Apasa-ma",this);
    m_Button1->setFixedWidth(80);
    m_Button1->setFixedHeight(50);
    m_Button1->setStyleSheet("border: 1px solid black;");
    m_leftLayout->addSpacerItem(new QSpacerItem(0, 25));
    m_leftLayout->addWidget(m_Button1, 0, Qt::AlignTop | Qt::AlignCenter);

//**************************************************************************************************





//ICON FRAME
    m_iconWidget = new QFrame();
    m_iconLayout = new QVBoxLayout(m_iconWidget);
    m_iconWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_iconWidget->setLineWidth(0);
    m_iconWidget->setFixedWidth(130);
    m_iconWidget->setFixedHeight(130);
//------------------------------------------------------------------------------
//ICON WIDGET
    m_icon = new QLabel();
    m_icon->setText("📖");
    m_icon->setFixedWidth(120);
    m_icon->setFixedHeight(120);
    m_icon->setAlignment(Qt::AlignCenter);
    m_icon->setStyleSheet("font-size: 50px; border: 1px solid black;");
    m_iconLayout->addWidget(m_icon);
//*************************************************************************






//MAIN FRAME
    m_indexWidget = new QStackedWidget();
    m_indexWidget->setStyleSheet("border: 1px solid black;");
    m_indexWidget->setFixedWidth(1040);
    m_indexWidget->setFixedHeight(540);
//---------------------------------------------------------------------------------------
//WIDGET1 MAIN FRAME
    m_indexLabel = new QLabel("Index View");
    m_indexLabel->setAlignment(Qt::AlignCenter);
    m_indexLabel->setStyleSheet("font-size: 20px;");
    m_indexWidget->addWidget(m_indexLabel);
    m_indexWidget->setCurrentIndex(0);
//---------------------------------------------------------------------------------------


//*************************************************************************








    mainLayout->addWidget(m_topWidget, 0, 1, 1, 2);
    mainLayout->addWidget(m_leftWidget, 1, 0);
    mainLayout->addWidget(m_iconWidget, 0, 0);
    mainLayout->addWidget(m_indexWidget, 1, 1, 1, 1);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

}



PanelWindowElev::~PanelWindowElev() = default;
