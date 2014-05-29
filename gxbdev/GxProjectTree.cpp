#include "GxProjectTree.h"
#include <QtCore>
#include <QtGui>
#include <Qt>
#include <QtXml/QtXml>
#include <QTextDocument>
#include "GxProjectItem.h"
#include "GxCreateProjectWindow.h"
#include "ui_GxCreateProjectWindow.h"

#define GXPRJ_DATACOLUMN    2
#define GXPRJ_DATAROLE      Qt::UserRole

GxProjectTree::GxProjectTree(QWidget *parent) :
    QTreeWidget(parent)
{

    // create the project as empty
    GxProjectItem* root_pji = new GxProjectItem("Untitled");
    insertTopLevelItem(0,*root_pji);

}

int GxProjectTree::AddProject()
{
    // reuse regular project items as a project root
    // the name of the project is stored in the label
    GxCreateProjectWindow* w = new GxCreateProjectWindow();

    if (w->exec() == QDialog::Accepted)
    {
        GxProjectItem* newitem = new GxProjectItem(w->ui->projectName->text());
        newitem->documentFullPath = w->ui->projectFile->text();
        newitem->refresh();
        addTopLevelItem(*newitem);
        return topLevelItemCount() - 1; // index to new project
    }
    else
        return -1; // no project created


}

int GxProjectTree::SelectedProject()
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
            for (int i =0; i < this->ProjectCount(); i++)
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

int GxProjectTree::ProjectCount()
{
    return topLevelItemCount();
}

const GxProjectItem &GxProjectTree::GetProject(int pos)
{
    QTreeWidgetItem* item = this->topLevelItem(pos);
    GxProjectItem* project_item = dynamic_cast<GxProjectItem*>(item);
    if (!project_item)
        throw item; // throw the item back if it doesnt have a pi attached
    return *project_item;
}




