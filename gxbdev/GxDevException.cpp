#include "GxDevException.h"
#include <exception>
#include <QTransform>

GxDevException::GxDevException(){}
GxDevException::GxDevException(QString name, QString file, int line)
    : _name(name), _file(file), _line(line)
{
    // no exception content here, this is on purpose, for now.
}

int GxDevException::line() const
{
    return _line;
}

QString GxDevException::file() const
{
    return _file;
}


QString GxDevException::name() const
{
    return _name;
}


