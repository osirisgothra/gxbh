#include "GxProjectItem.h"
#include <QStringBuilder>
#define _TLW QApplication::topLevelWidgets()[0]


GxProjectItem::GxProjectItem(QString name)
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

const QWidget *GxProjectItem::ownerAppWindow()
{
    // used for dialogs, messageboxes, and for general garbage collection (undeleted objects' parent widget set to this)
    return QApplication::topLevelWidgets().first();
}

