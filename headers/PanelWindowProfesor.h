#ifndef PANELWINDOWPROFESOR_H
#define PANELWINDOWPROFESOR_H
#include <stdexcept>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QPushButton>
/**
 * The PanelWindowProfesor class represents a graphical user interface (GUI)
 * component tailored for use by professors in an educational system.
 *
 * This class extends a panel or window component to provide specialized
 * functionality and features needed for professors to interact with the system.
 * It may include methods and attributes for displaying professor-specific information,
 * handling user input, and managing data operations related to the professor's activities.
 *
 * Responsibilities of this class may include:
 * - Displaying relevant information and available functionalities for professors.
 * - Providing an interface to manage courses, assignments, or student data.
 * - Capturing and responding to user interactions specific to this user role.
 * - Ensuring data integrity and accuracy when interfacing with external systems or databases.
 *
 * The implementation may rely on additional supporting classes or integrate with
 * underlying back-end systems to fetch or update necessary data.
 */

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