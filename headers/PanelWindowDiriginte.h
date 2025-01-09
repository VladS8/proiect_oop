#ifndef PANELWINDOWDIRIGINTE_H
#define PANELWINDOWDIRIGINTE_H
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QPushButton>

/**
 * @class PanelWindowDiriginte
 * @brief Represents a panel window specifically designed for "Diriginte" functionalities.
 *
 * This class is used to manage the UI components and functionalities associated with
 * "Diriginte" (classmaster) operations within an application. It provides necessary methods
 * and attributes to handle related processes and user interactions.
 *
 * The PanelWindowDiriginte class is intended to facilitate the management of data, display
 * elements, and interactions specific to "Diriginte" tasks while maintaining ease of use
 * and modularity.
 *
 * Potential operations may include data display, updates, interaction handling,
 * and triggering events related to the classmaster UI elements.
 */

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
