#include "GxConfigManagement.h"
#include <QMap>
#include <KDE/KSharedConfig>
#include <QObject>
#include <QPalette>

// 1 = automatic use of rgb() instead of rgba() when alpha is 100% opaque (overrides caller's demand for rgba in some cases)
#define GX_CONFIGMANAGEMENT_AUTO_RGB_WHEN_OPAQUE 0

GxConfigManagement::GxConfigManagement(QObject *parent) :
    QObject(parent)
{
    // read any cached globals
    m_singleClick = getConfigBool("kdeglobals","KDE","SingleClick");
}

QString GxConfigManagement::goodStyle()
{
    // dont use getConfigColorStyle (since translation is not needed)
    return "color: rgb(" + getConfigString("kdeglobals","Colors:View","ForegroundPositive","0,192,0") + "); ";
}

QString GxConfigManagement::badStyle()
{
    // see goodStyle()
    return "color: rgb(" + getConfigString("kdeglobals","Colors:View","ForegroundNegative","192,0,0") + "); ";
}

QString GxConfigManagement::getConfigColorStyle(QString config, QString section, QString setting, QString style_element, QColor _default, bool useAlpha)
{
    // use this function when a default QColor (input) is unknown, and alpha usage
    // is a possibility.

    // though alpha isn't used by kde's color settings, it may be used in other places
    // so to keep compatibility with that, this function offers a place for it
    QColor _thecolor = getConfigColor(config,section,setting,_default);
#if GX_CONFIGMANAGEMENT_AUTO_RGB_WHEN_OPAQUE == 1
    if (_thecolor.alphaF() == 1.0F ); then
         useAlpha = false;   // not needed when alpha is opaque
#endif

    return ""
            + style_element + ": "
            + (useAlpha? "rgba" : "rgb")
            + "("
            + QString::number(_thecolor.red())
            + ","
            + QString::number(_thecolor.green())
            + ","
            + QString::number(_thecolor.blue())
            + (useAlpha? ("," + QString::number(_thecolor.alphaF())) : "")
            + ";";
}

bool GxConfigManagement::singleClick() const
{
    return m_singleClick;
}

bool GxConfigManagement::getConfigBool(QString config, QString section, QString setting, bool _default)
{
    QString value = getConfigString(config,section,setting,"none").toLower();
    if (value == "none")
        return _default;
    else
    {
        if (value == "true" || value == "yes")
            return true;
        else if (value == "false" || value == "no")
            return false;
        else
            return _default;
    }
}

QColor GxConfigManagement::getConfigColor(QString config, QString section, QString setting, QColor _default)
{
    // since kde color entries omit an alpha value, we do not deal with alpha here
    // other configs may wish to do otherwise but at this time no alpha config values need dealt with
    // the settings value must be in the form of: NUMBER,NUMBER,NUMBER. Whitespace is allowed and will be
    // trimmed from the string (in the first instruction below)

    QString _color = getConfigString(config,section,setting,"default").remove(QRegExp("\s"));

    if ( _color != "default")
    {
        if (_color.count(",") == 2 && _color.count(QRegExp("^[0-9,]*",Qt::CaseInsensitive,QRegExp::RegExp2)) == 0)
        {
            QStringList splits = _color.split(',',QString::SkipEmptyParts);
            if (splits.count() == 3)     // must be three
            {
                bool ok=true; // if any part of the op fails, returns the default
                int failcount=0;
                int r,g,b;
                r = splits.at(0).toInt(&ok); failcount += ok?0:1;
                g = splits.at(1).toInt(&ok); failcount += ok?0:1;
                b = splits.at(2).toInt(&ok); failcount += ok?0:1;
                if (failcount == 0)
                {
                    return QColor(r,g,b);
                }
            }
        }

    }
    return _default;
}

QString GxConfigManagement::getConfigString(QString config, QString section, QString setting, QString _default)
{
    KSharedConfig::Ptr the_config = KSharedConfig::openConfig(config);
    QMap<QString,QString> kdemap = the_config.constData()->entryMap(section);
    if (kdemap.contains(setting))
        return kdemap.value(setting);
    else
        return _default;
}

