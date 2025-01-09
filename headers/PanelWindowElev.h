#ifndef PANELWINDOWELEV_H
#define PANELWINDOWELEV_H
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
    QLabel *m_leftLabel;

    // ICON FRAME
    QFrame *m_iconWidget;
    QVBoxLayout *m_iconLayout;
    QLabel *m_icon;


public:
    /**
     * @brief Constructs a new PanelWindowElev object.
     *
     * This constructor initializes a new instance of the PanelWindowElev class,
     * which is a QMainWindow object designed for a specific student's panel.
     *
     * @param parent The parent widget for this QMainWindow. Can be nullptr.
     * @param numeElev The name of the student associated with this panel.
     * @param clasaElev The class or grade level of the student.
     *
     * @return A new instance of the PanelWindowElev class.
     */
    explicit PanelWindowElev(QWidget *parent = nullptr, const QString &numeElev = "", const QString &clasaElev = "");
    ~PanelWindowElev() override;

    private slots:
        void showGradesOnButtonClicked();
};

#endif // PANELWINDOWELEV_H