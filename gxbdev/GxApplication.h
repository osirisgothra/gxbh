#ifndef GXAPPLICATION_H

#define GXAPPLICATION_H

#include <KDE/KApplication>
#include "GxConfigManagement.h"


class GxApplication : public KApplication
{
public:
    const GxConfigManagement* config;
    GxApplication();

    static const GxApplication* instance();
    static const KAboutData* aboutData();
};

#endif // GXAPPLICATION_H
