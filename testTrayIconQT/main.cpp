#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <qsystemtrayicon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
