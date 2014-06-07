#include "GxProjectItem.h"
#include <QStringBuilder>
#include "GxDevException.h"
#define _TLW QApplication::topLevelWidgets()[0]
#include <boost/cast.hpp>
#include "GxSyntaxHighlighter.h"

using namespace boost;

// custom values for SetData/Data
#define GXPCOL 12
#define GXPROLE Qt::UserRole+GXPCOL
//shortcut for above
#define GXPCR GXPCOL,GXPROLE
// used for static operations

GxProjectItem::GxProjectItem(QString name):_subWindowLink(NULL)
{
    QFileInfo fi(name);

    // if a physical file handle differently
    if (fi.exists())
    {

        documentFullPath = fi.absolutePath();
        ondisk = true;
        openedDocumentContent = NULL;
    }
    else // not a real file (yet)
    {
        documentFullPath = QDir::current().absolutePath();
        ondisk = false;
        openedDocumentContent = new QTextDocument("",this);
        openedDocumentContent->setModified();
    }

    documentDispName = fi.fileName();
    // create the tree widget item using the short name as the label
    owneritem = new QTreeWidgetItem();
    refresh();

    // LINK the owneritem so it can be reverse-connected to this item
    setref(NULL);


}
bool GxProjectItem::isOpen() const
{
    return openedDocumentContent != NULL;
}

bool GxProjectItem::setOpen(bool value)
{
    Q_ASSERT(!(!isOnDisk() && !isOpen())); // never should be this

    // asking to close - but not already closed
    if (isOpen() && value == false)
    {
        // save first if needed
        // handle the ui for closing
        if (openedDocumentContent->isModified())
        {
            if (QMessageBox::question(_TLW, "Save?","Fille not Saved, Save it Now?") == QMessageBox::Yes)
            {
                // but fail and do not close if writing failed
                if (!QTextDocumentWriter(documentFilePathName()).write(openedDocumentContent))
                    return false;
            }
        }
        // and then close by deleting the item and setting ondisk, etc
        ondisk = true;
        delete openedDocumentContent;
        delete _highlighter;
        openedDocumentContent = NULL;
        return true; // ... and it all worked out
    }
    // asking to open - but not already open
    else if (!isOpen() && value == true)
    {        
        QFile docfile(documentFilePathName());
        if (docfile.exists())
        {
            if (docfile.open(QFile::ReadOnly))
            {
                openedDocumentContent = new QTextDocument(this);
                _highlighter = new GxSyntaxHighlighter(openedDocumentContent);
                Q_ASSERT(openedDocumentContent != NULL);
                openedDocumentContent->setPlainText(QString(docfile.readAll()));
                docfile.close();
                return true;
            }
            else
            {
                QString msg = docfile.errorString();
                QMessageBox::critical(_TLW,"Cannot Open File",msg);
            }
        }
        else
        {
            QString msg = docfile.errorString();
            QMessageBox::critical(_TLW,"Cannot Locate File",msg);
        }
    }
    // asking for the same state, but already there
    else
    {
        // considered successful because the caller asked for the
        // current state (ie, open=true), and the end result is
        // what the caller asked for.
        return true;
    }

    // when ending up here, it is because the state is NOT
    // what the caller asked for, so we consider it a failure
    // fall through for erronous states
    return false;
}
bool GxProjectItem::isOnDisk() const
{
    return ondisk;
}

QString GxProjectItem::documentFilePathName()
{
    // does not guarentee a legal, nonempty, or existing path! utility to combine (for others to test)
    QString retval = this->documentFullPath;
    return retval;
}

void GxProjectItem::refresh()
{
    owneritem->setText(0,documentDispName);                             // label (the "display" name)
    owneritem->setText(1,QString::number(owneritem->childCount()));     // the number of subitems in this item
    owneritem->setText(2,documentFullPath);                             // full path to file
    owneritem->setText(3,isOpen() ? "Yes" : "No");                      // opened?
    owneritem->setText(4,isOpen() ?
                           openedDocumentContent ?
                               QString::number(openedDocumentContent->toPlainText().length()) : "Error"
                             : "N/A");

}

GxProjectItem::operator QTextDocument *()
{
    Q_ASSERT(!(!isOnDisk() && !isOpen())); // never should be this
    if (isOnDisk() && !isOpen())
        setOpen(true);
    return this->openedDocumentContent;
}



GxProjectItem::operator QTreeWidgetItem *()
{
    refresh();  // synchronize states for treeview
    return this->owneritem;
}

const GxProjectItem &GxProjectItem::nextItem()
{
    if (isTopLevel())
        GX_THROW(ProjItem);
    int item = owneritem->parent()->indexOfChild(owneritem);
    return childItem(item+1);

}

const GxProjectItem &GxProjectItem::prevItem()
{
    if (isTopLevel())
        GX_THROW(ProjItem);
    int item = owneritem->parent()->indexOfChild(owneritem);
    return childItem(item-1);
}

const GxProjectItem &GxProjectItem::childItem(int pos)
{
    if ((pos+1) > owneritem->childCount())
        GX_THROW(ProjItem);
    return getref(owneritem->child(pos));

}

const GxProjectItem &GxProjectItem::parentItem()
{
    if (isTopLevel())
        GX_THROW(ProjItem);
    else
        return *((GxProjectItem*)owneritem->parent()->data(GXPCR).value<void*>());
}


const GxProjectItem &GxProjectItem::insertSubItem(QString path, QString name, bool _ondisk, bool _opened, QTextDocument *_opencontent)
{
    GxProjectItem* projitem = new GxProjectItem(name);

    projitem->setParent(parent());    // IMPORTANT: propagate backwards to the top so we can find ourselves later on



    projitem->documentFullPath = path;
    projitem->ondisk = _ondisk;
    projitem->openedDocumentContent = _opened? _opencontent:NULL;
    projitem->refresh(); // synchronize <-> treeitem

    owneritem->addChild(projitem->owneritem); // owneritem is linked to projitem, so the pointer wont be lost

    return *projitem; // could be discarded here

}


GxProjectItem& GxProjectItem::getref(QTreeWidgetItem* item)
{
    if (!item)
        item = owneritem;
    GxProjectItem* datavalue = item->data(GXPCR).value<GxProjectItem*>();

    if (!datavalue)
        GX_THROW(ProjItem);
    return *datavalue;
}

void GxProjectItem::setref(QTreeWidgetItem *item, GxProjectItem *ref)
{
    if (!ref)
        ref = this;
    if (!item)
        item = owneritem;
    item->setData(GXPCR,QVariant::fromValue<GxProjectItem*>(ref));
}

bool GxProjectItem::isTopLevel()
{
    return (owneritem->parent() == NULL);
}

QMdiSubWindow *GxProjectItem::subWindowLink() const
{
    return _subWindowLink;
}

void GxProjectItem::setSubWindowLink(QMdiSubWindow *subWindowLink)
{
    _subWindowLink = subWindowLink;
}


GxProjectItem &GxProjectItem::itemtoref(const QTreeWidgetItem& item)
{
    GxProjectItem GX_DUMMY_ITEM("GX_DUMMY_ITEM");
    // all exceptions are done at getref
    return GX_DUMMY_ITEM.getref(const_cast<QTreeWidgetItem*>(&item));
}

void GxProjectItem::reftoitem(const QTreeWidgetItem& item, const GxProjectItem& ref)
{
    GxProjectItem GX_DUMMY_ITEM("GX_DUMMY_ITEM");
    // all exceptions @ setref
    GX_DUMMY_ITEM.setref(const_cast<QTreeWidgetItem*>(&item), const_cast<GxProjectItem*>(&ref));
}
