#ifndef GXPROJECTTREE_H
#define GXPROJECTTREE_H

#include <QtCore>
#include <QtGui>

class GxProjectTree;

class GxProjectItem
{
    friend class GxProjectTree;
protected:
    GxProjectItem(QString name, GxProjectTree* _owner, QTreeWidgetItem* _owneritem);
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
    void setOpen(bool value);

    bool isOnDisk() const;
    void setOndisk(bool value);


private:
    bool ondisk;

    GxProjectTree* owner;
    QTreeWidgetItem* owneritem;
};


class GxProjectTree : public QTreeWidget
{
    Q_OBJECT
    friend class GxProjectItem;
public:
    explicit GxProjectTree(QWidget *parent = 0);

    const GxProjectItem& project(int pos);



signals:

public slots:

};

#endif // GXPROJECTTREE_H
