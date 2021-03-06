#include "GxMainWindow.h"
#include <qtermwidget.h>
#include "ui_GxMainWindow.h"
#include <QtGui>
#include <QtCore>
#include "GxProjectItem.h"
#include "GxProjectTree.h"
#include <KDE/KTextEdit>

GxMainWindow::GxMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GxMainWindow)
{
    ui->setupUi(this);
    QApplication::processEvents();    

}

GxMainWindow::~GxMainWindow()
{
    delete ui;
}

void GxMainWindow::on_exec_pressed()
{
    QString str = ui->cmdline->text() + "\n";
    ui->term->sendText(str);
}

void GxMainWindow::on_actionAdd_New_Item_triggered()
{
    bool pressed = false;
    QString docname = QInputDialog::getText(this,
                                            "Specify Filename",
                                            "Please enter a file name for this document, it will be used to identify it within the project, and when saving the document later. Make sure to include the desired extension (ie, file.txt):",
                                            QLineEdit::Normal,
                                            "Untitled" + QString::number(open_documents.count()+1),&pressed
                                           );
    if (pressed)
    {        
        //TODO:
        // SelectedProject->AddSubItem (if no selected)
        // OR
        // SelectedItem->AddSubItem
        //

    }

}

void GxMainWindow::on_actionNew_Project_triggered()
{
    this->ui->projtree->AddProject();
}

void GxMainWindow::on_projtree_doubleClicked(const QModelIndex &index)
{
    GxProjectItem& item = ui->projtree->projectItemFromIndex(index);
    if (item.subWindowLink() == NULL)
    {
        item.setOpen(true); // validity checking done inside here
        if (item.isOpen())
        {

            KTextEdit *win = new KTextEdit();
            win->setLineWrapMode(KTextEdit::NoWrap);
            win->setCheckSpellingEnabled(false);
            win->setDocument(item.openedDocumentContent);
            win->document()->setDefaultFont(QFont("Ubuntu Mono",14));
            QPalette* palette = new QPalette();
            palette->setColor(QPalette::Base,QColor(0,0,0));
            palette->setColor(QPalette::Text,QColor(128,128,128));
            win->setPalette(*palette);

            QMdiSubWindow* subwin = ui->mdiArea->addSubWindow(win);
            item.setSubWindowLink(subwin);
            item.subWindowLink()->setWindowTitle(item.documentDispName);
            subwin->show();;
            subwin->setWindowState(Qt::WindowMaximized);
        }
    }
    else
    {
        item.subWindowLink()->setFocus();
    }

}

void GxMainWindow::on_actionAbout_triggered()
{

}
