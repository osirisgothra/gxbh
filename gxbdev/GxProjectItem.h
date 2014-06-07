#ifndef __GXPROJECTITEM_H__
#define __GXPROJECTITEM_H__

#include <QtCore>
#include <QtGui>
#include <QMetaType>

class GxProjectTree;
class GxSyntaxHighlighter;

class GxProjectItem : public QObject
{
    Q_OBJECT

    friend class GxProjectTree;

protected:

    // a GxProjectItem can only can be created by the GxProjectTree

    GxProjectItem(QString name);

public:

    // TODO: convert to setter/getter methods and attach refresh() to each one

    QString documentFullPath;
    QString documentDispName;
    QTextDocument* openedDocumentContent;

    // lookups

    const GxProjectItem& nextItem();
    const GxProjectItem& prevItem();
    const GxProjectItem& childItem(int pos);
    const GxProjectItem& parentItem();

    // change actions

    const GxProjectItem& insertSubItem(QString path, QString name, bool _ondisk, bool _opened, QTextDocument* _opencontent);
    void setSubWindowLink(QMdiSubWindow *subWindowLink);
    void clearSubWindowLink() { _subWindowLink = NULL; }

    // queries

    bool isOpen() const;
    bool setOpen(bool value);
    bool isOnDisk() const;
    void setOndisk(bool value);
    QString documentFilePathName();
    QMdiSubWindow *subWindowLink() const;
    bool isTopLevel();

    // type conversion

    operator QTreeWidgetItem*();    
    operator QTextDocument*();

    // mappable actions

public slots:

    void refresh(); // synchronizes data between QTreeWidgetItem and GxProjectItem

    // internal data

private:
    bool ondisk;
    QTreeWidgetItem* owneritem;
    GxProjectItem& getref(QTreeWidgetItem *item);
    void setref(QTreeWidgetItem* item, GxProjectItem* ref = NULL); // NULL means (this)
    QMdiSubWindow* _subWindowLink;
    GxSyntaxHighlighter* _highlighter;
    static GxProjectItem& itemtoref(const QTreeWidgetItem &item);
    static void reftoitem(const QTreeWidgetItem &item, const GxProjectItem &ref); // NULL means (this)    

};

Q_DECLARE_METATYPE(GxProjectItem*)  // allows this item to be used with QVariant (for QTreeWidgetItem->[set]Data() calls)


#endif
