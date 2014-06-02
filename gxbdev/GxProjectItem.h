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
    bool isTopLevel();

    const GxProjectItem& insertSubItem(QString path, QString name, bool _ondisk, bool _opened, QTextDocument* _opencontent);

    bool isOpen() const;
    bool setOpen(bool value);

    bool isOnDisk() const;
    void setOndisk(bool value);
    QString documentFilePathName();
    QMdiSubWindow *subWindowLink() const;
    void setSubWindowLink(QMdiSubWindow *subWindowLink);
    void clearSubWindowLink() { _subWindowLink = NULL; }
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
    GxProjectItem& getref(QTreeWidgetItem *item);
    void setref(QTreeWidgetItem* item, GxProjectItem* ref = NULL); // NULL means (this)
    QMdiSubWindow* _subWindowLink;
    GxSyntaxHighlighter* _highlighter;
    static GxProjectItem& itemtoref(const QTreeWidgetItem &item);
    static void reftoitem(const QTreeWidgetItem &item, const GxProjectItem &ref); // NULL means (this)

};

Q_DECLARE_METATYPE(GxProjectItem*)


#endif
