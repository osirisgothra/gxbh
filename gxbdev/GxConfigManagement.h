#ifndef GXCONFIGMANAGEMENT_H
#define GXCONFIGMANAGEMENT_H

#include <QObject>
#include <QColor>

class GxConfigManagement : public QObject
{
    Q_OBJECT
public:
    explicit GxConfigManagement(QObject *parent = 0);

    QString goodStyle();
    QString badStyle();
    bool singleClick() const;

    bool getConfigBool(QString config, QString section, QString setting, bool _default=false);
    QColor getConfigColor(QString config, QString section, QString setting, QColor _default=QColor(0,0,0));
    QString getConfigString(QString config, QString section, QString setting, QString _default=QString(""));


    QString getConfigColorStyle(QString config, QString section, QString setting, QString style_element = "color", QColor _default = QColor(0,0,0), bool useAlpha=false);
signals:

public slots:

private:
    bool m_singleClick;

};

#endif // GXCONFIGMANAGEMENT_H
