#ifndef GXDEVEXCEPTION_H
#define GXDEVEXCEPTION_H

#include <boost/exception/all.hpp>
#include <QtCore>
#include <QString>

using namespace std;

#define NewGxDevException(name) new GxDevException(tr(#name),__FILE__,__LINE__)
#define NewGxDevProjEx NewGxDevException(Project)
#define NewGxDevAppEx NewGxDevException(Application)
#define NewGxDevProjItemEx NewGxDevException(ProjectItem)
#define NewGxDevProjTreeEx NewGxDevException(ProjectTree)
#define NewGxDevProjDocEx NewGxDevException(ProjectDocument)
#define NewGxDevProjFileEx NewGxDevException(ProjectFile)
#define GX_THROW(nam) throw NewGxDev##nam##Ex

class GxDevException : public boost::exception
{
public:
    GxDevException(QString name, QString file, int line);
    ~GxDevException() throw() {}

    QString name() const;
    QString file() const;
    int line() const;


protected:
    GxDevException();

    QString _name;
    QString _file;
    int _line;

};

#endif // GXDEVEXCEPTION_H
