#include <QApplication>
#include "headers/LoginWindow.h"
#include "headers/RegisterWindow.h"
#include "headers/PanelWindowElev.h"





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginWindow l;
    RegisterWindow r;
    PanelWindowElev pe;
    l.show();
    return QApplication::exec();


}