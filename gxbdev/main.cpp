#include "GxMainWindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GxMainWindow w;
    w.show();
    // Simple test window
    return a.exec();
}
