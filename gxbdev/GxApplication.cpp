#include "GxApplication.h"
#include "GxMainWindow.h"
#include <KDE/KApplication>
#include <KDE/KCmdLineArgs>
#include <KDE/KMessageBox>
#include <KDE/KAboutData>

KAboutData* aboutData= new KAboutData(
                                i18n("gxbase").toUtf8(),
                                i18n("gxbase").toUtf8(),
                                ki18n("gxbdev"),
                                i18n("0.2.0.0").toUtf8(),
                                ki18n("GxBase Development IDE"),
                          KAboutData::License_GPL_V2,
                                ki18n("(C)2014 Paradisim Enterprises, LLC"),
                                ki18n("Please read the README file(s) distributed with this program."),
                                i18n("http://www.gitorious.org/+paradisim").toUtf8(),
                                i18n("osirisgothra@hotmail.com").toUtf8()
                                      );


int main(int argc, char *argv[])
{
    // COMMAND LINE PARSING SECTION


    KCmdLineArgs::init(argc,argv,aboutData);
    KCmdLineOptions options;        options.add(i18n("version").toLocal8Bit(),ki18n("Report version and exit"));
    KCmdLineArgs::addCmdLineOptions(options);
    GxApplication app; // Our documentation says to put these items here.
    GxMainWindow w;    // <-------/
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();

    if (args->isSet("version"))
    {
        KMessageBox::information(0,"gxbdev 0.2.0.0 (pre-release)","Version");
        return 0;
    }

    // APPLICATION START-UP SECTION

    w.show();
    return app.exec();
}
