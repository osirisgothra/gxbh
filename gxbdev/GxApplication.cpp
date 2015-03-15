#include "GxApplication.h"
#include "GxMainWindow.h"
#include <KDE/KApplication>
#include <KDE/KCmdLineArgs>
#include <KDE/KMessageBox>
#include <KDE/KAboutData>
#include <boost/cast.hpp>

KAboutData* aboutData;

GxApplication::GxApplication():
    KApplication(),
    config(new GxConfigManagement(0))
{}

const GxApplication *GxApplication::instance()
{
    return boost::polymorphic_cast<GxApplication*,QCoreApplication>(KApplication::instance());
}

const KAboutData *GxApplication::aboutData()
{
    return ::aboutData; // the data sitting on the global namespace is just above the constructor
}


int main(int argc, char *argv[])
{
    // COMMAND LINE PARSING SECTION

      KAboutData aboutData(
                "gxbase",
                "gxbase",
                ki18n("gxbdev"),
                "0.2.0.1",
                ki18n("GxBase Development IDE"),
          KAboutData::License_GPL_V2,
                ki18n("(C)2014 Paradisim Enterprises, LLC"),
                ki18n("Please read the README file(s) distributed with this program."),
                "http://www.gitorious.org/+paradisim",
                "osirisgothra@hotmail.com"
                      );



    KCmdLineArgs::init(argc,argv,&aboutData);

    KCmdLineOptions options;        options.add("appversion",ki18n("Report Application-specific version info and exit"));
    KCmdLineArgs::addCmdLineOptions(options);
    GxApplication app; // Our documentation says to put these items here.
    GxMainWindow* w = new GxMainWindow(0);    // <-------/ and the session manager will delete this
    w->setObjectName("gxbdev#mainwindow");
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();

    QPalette pal;
    pal.setColor(QPalette::Base,Qt::black);
    pal.setColor(QPalette::Text,Qt::gray);
    app.setPalette(pal);

    if (args->isSet("appversion"))
    {
        KMessageBox::information(0,"gxbdev 0.2.0.1 (pre-release)","Version");
        return 0;
    }

    // APPLICATION START-UP SECTION

    w->show();
    return app.exec();


}

