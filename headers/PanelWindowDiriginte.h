#ifndef PANELWINDOWDIRIGINTE_H
#define PANELWINDOWDIRIGINTE_H
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QPushButton>


#include "Subject.h"

class PanelWindowDiriginte : public QMainWindow {
    Q_OBJECT

private:
    QString m_idDiriginte;
    QWidget *mainWidget;
    QGridLayout *mainLayout;

    // INDEX FRAME
    QStackedWidget *m_indexWidget;
    QLabel *m_indexLabel;

    // TOP FRAME
    QFrame *m_topWidget;
    QHBoxLayout *m_topLayout;
    QLabel *m_welcomeMessage;
    QLabel *m_testLabel;
    QLabel *m_testLabel2;

    // LEFT FRAME
    QFrame *m_leftWidget;
    QVBoxLayout *m_leftLayout;
    QPushButton *m_showStudentsButton;

    // ICON FRAME
    QFrame *m_iconWidget;
    QVBoxLayout *m_iconLayout;
    QLabel *m_icon;

public:
    explicit PanelWindowDiriginte(QWidget *parent = nullptr, const QString &numeDiriginte = "", const QString &numeClasa = " ", const QString &idDiriginte = " ");
    ~PanelWindowDiriginte() override;

    private slots:
        void showStudentsOnPushButtonClicked(const QString& idDiriginte);
};


#endif //PANELWINDOWDIRIGINTE_H
