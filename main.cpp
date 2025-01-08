#include <QApplication>
#include "headers/LoginWindow.h"
#include "headers/RegisterWindow.h"
#include "headers/PanelWindowElev.h"
#include "headers/PanelWindowProfesor.h"
#include <iostream>
#include "headers/Observer.h"

#include "headers/PanelWindowDiriginte.h"

int main(int argc, char *argv[])
{
    try {
        QApplication app(argc, argv);
        LoginWindow l;
        // RegisterWindow r;
        // PanelWindowElev pe;
        // PanelWindowDiriginte pp;
        // r.addObserver(&pp);


        l.show();
        return QApplication::exec();

    } catch (const std::exception &e) {
        std::cerr << "A apărut o excepție: " << e.what() << std::endl;
        return EXIT_FAILURE;

    } catch (...) {
        std::cerr << "A apărut o eroare necunoscută!" << std::endl;
        return EXIT_FAILURE;
    }
}
