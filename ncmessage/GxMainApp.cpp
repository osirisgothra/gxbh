#include "GxMainApp.h"

GxMainApp::GxMainApp(QObject *parent) :
    QCoreApplication(parent)
{
    connect(this,SIGNAL(aboutToQuit()),this,SLOT(AboutToQuit()));
    connect(this,SIGNAL(unixSignal(int)),this,SLOT(UnixSignal(int)));


}
