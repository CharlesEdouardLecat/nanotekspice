#include <QtWidgets>
#include <QApplication>
#include "src/editor/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
