#ifndef PANELWINDOWPROFESOR_H
#define PANELWINDOWPROFESOR_H
#include <stdexcept>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QPushButton>


class PanelWindowProfesor : public QMainWindow
{
    Q_OBJECT

private:
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
    QPushButton *m_showGradesButton;
    QPushButton *m_manageStudentsButton;
    QPushButton *m_showStudentsButton;

    // ICON FRAME
    QFrame *m_iconWidget;
    QVBoxLayout *m_iconLayout;
    QLabel *m_icon;


public:
    explicit PanelWindowProfesor(QWidget *parent = nullptr, const QString &numeProfesor = "", const QString &materieProfesor = "");
    ~PanelWindowProfesor() override;

    private slots:
        void showStudentsOnPushButtonClicked(const QString& idDiriginte);
};

#endif // PANELWINDOWPROFESOR_H