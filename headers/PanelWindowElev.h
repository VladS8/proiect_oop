#ifndef PANELWINDOWELEV_H
#define PANELWINDOWELEV_H
#include <stdexcept>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QPushButton>

class PanelWindowElev : public QMainWindow
{
    Q_OBJECT


private:
    QWidget *mainWidget;
    QGridLayout *mainLayout;

    //INDEX FRAME
    QStackedWidget *m_indexWidget;
    QLabel *m_indexLabel;
    //TOP FRAME
    QFrame *m_topWidget;
    QHBoxLayout *m_topLayout;
    QLabel *m_welcomeMessage;
    QLabel *m_testLabel;
    QLabel *m_testLabel2;
    //LEFT FRAME
    QFrame *m_leftWidget;
    QVBoxLayout *m_leftLayout;
    QPushButton *m_Button1;
    //ICON FRAME
    QFrame *m_iconWidget;
    QVBoxLayout *m_iconLayout;
    QLabel *m_icon;



public:

    explicit PanelWindowElev(QWidget *parent = nullptr, const QString &numeElev = "", const QString &clasaElev = "");
    ~PanelWindowElev() override;


    private slots:

};

#endif // PANELWINDOWELEV_H
