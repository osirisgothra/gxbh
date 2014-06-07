#include "GxProjectTree.h"
#include <QtCore>
#include <QtGui>
#include <Qt>
#include <QtXml/QtXml>
#include <QTextDocument>
#include "GxProjectItem.h"
#include "GxCreateProjectWindow.h"
#include "ui_GxCreateProjectWindow.h"
#include <GxDevException.h>

#define GXPRJ_DATACOLUMN    2
#define GXPRJ_DATAROLE      Qt::UserRole

GxProjectTree::GxProjectTree(QWidget *parent) :
    QTreeWidget(parent)
{

    // create the project as empty
    GxProjectItem* root_pji = new GxProjectItem("Untitled");
    insertTopLevelItem(0,*root_pji);

}

int GxProjectTree::addProject()
{
    // reuse regular project items as a project root
    // the name of the project is stored in the label
    GxCreateProjectWindow* w = new GxCreateProjectWindow();
    w->projectDispname = "gxbase";
    w->projectFilename = "/gxbase/project.gxb";
    w->projectWantItems = true;
    w->projectItems.append("/gxbase/res/bashrc");
    w->projectItems.append("/gxbase/res/bash-helpers");
    w->projectItems.append("/gxbase/res/bash-vars");
    w->projectItems.append("/gxbase/res/bash-traps");
    w->projectItems.append("/gxbase/res/bash-aliases");
    w->projectItems.append("/gxbase/res/bash-settings");
    w->projectItems.append("/gxbase/res/bash-bindings");

    if (true)// (w->exec() == QDialog::Accepted)
    {

        GxProjectItem* newitem = new GxProjectItem(w->projectDispname);

        newitem->setParent(this);

        newitem->documentFullPath = w->projectFilename;
        newitem->documentDispName = w->projectDispname;
        newitem->refresh(); // sync between item<->treeitem

        if (w->projectWantItems)
        {
            // add their subitems as well
            foreach (QString pth, w->projectItems)
            {
                QFileInfo p(pth);
                if (p.exists())
                    newitem->insertSubItem(pth,p.baseName(),true,false,NULL);

            }

        }
        addTopLevelItem(*newitem);

        return topLevelItemCount() - 1; // index to new project
    }
    else
        return -1; // no project created


}

int GxProjectTree::selectedProject()
{
    if (topLevelItemCount() > 0)
    {
        if (selectedItems().count() == 0)
        {
            return 0;   // topmost project, if any
        }
        else
        {
            bool atTop = false;
            QTreeWidgetItem* selitem = this->selectedItems().at(0);
            while (!atTop)
            {
                if (selitem->parent() != NULL)
                    selitem = selitem->parent();
                else
                    atTop = true;
            }
            Q_ASSERT(atTop);
            for (int i =0; i < this->projectCount(); i++)
            {
                if (selitem == topLevelItem(i))
                    return i;
            }
            Q_ASSERT(FALSE);
            return -1; // didn't exist, which should not happen
        }
    }
    else
        return -1; // no items, so no projects (and therefore no selection possible)
}

int GxProjectTree::projectCount()
{
    return topLevelItemCount();
}

GxProjectItem &GxProjectTree::findBySubWindowLink(QMdiSubWindow *link)
{
    int count = topLevelItemCount();
    if (count > 0)
    {
        foreach (GxProjectItem* child, findChildren<GxProjectItem*>())
        {
            if (child->subWindowLink() == link)
                return *child;
        }
    }
    GX_THROW(ProjItemNf);

}

GxProjectItem &GxProjectTree::getProject(int pos)
{
    QTreeWidgetItem* item = this->topLevelItem(pos);
    GxProjectItem* project_item = dynamic_cast<GxProjectItem*>(item);
    if (!project_item)
        throw item; // throw the item back if it doesnt have a pi attached
    return *project_item;
}

GxProjectItem &GxProjectTree::projectItemFromIndex(const QModelIndex &index)
{
    QTreeWidgetItem* item = QTreeWidget::itemFromIndex(index);
    if (item)
        return GxProjectItem::itemtoref(*item);
    else
        GX_THROW(ProjTree);
}




