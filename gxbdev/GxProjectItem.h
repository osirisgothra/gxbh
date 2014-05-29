#ifndef __GXPROJECTITEM_H__
#define __GXPROJECTITEM_H__

#include <QtCore>
#include <QtGui>

class GxProjectTree;
class GxProjectItem : public QObject
{
    Q_OBJECT

    friend class GxProjectTree;

protected:
    GxProjectItem(QString name);
    const QWidget *ownerAppWindow();
public:

    // publicly alterable data

    QString documentFullPath;
    QString documentDispName;

    QTextDocument* openedDocumentContent;
    // objects to give access to (but not allow pointers to be deleted)
    const GxProjectItem& next();
    const GxProjectItem& prev();
    const GxProjectItem& child(int pos);
    const GxProjectItem& parent();

    const GxProjectItem& insertSubItem(QString path, QString name, bool _ondisk, bool _opened, QTextDocument* _opencontent);

    bool isOpen() const;
    bool setOpen(bool value);

    bool isOnDisk() const;
    void setOndisk(bool value);
    QString documentFilePathName();

    // type conversion

    // get the tree widget item, used for inserting project items into the list view
    operator QTreeWidgetItem*();
    // get the text document associated, used for setting the text document implicitly
    operator QTextDocument*();
public slots:
    void refresh(); // refresh data to tree item so it shows proper in tree view

private:
    bool ondisk;

    QTreeWidgetItem* owneritem;

};


#endif
