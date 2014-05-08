#include "terminal.h"
#include "GXMainWindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GXMainWindow w;
    w.show();
    // Simple test window
    return a.exec();
}
