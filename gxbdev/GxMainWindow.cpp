#include "GxMainWindow.h"
#include <qtermwidget.h>
#include "ui_GxMainWindow.h"
#include <QtGui>
#include <QtCore>
#include "GxProjectItem.h"
#include "GxProjectTree.h"
#include <KDE/KTextEdit>
#include <KDE/KMainWindow>
#include <KDE/KApplication>
#include <KDE/KHelpMenu>
#include <boost/cast.hpp>


GxMainWindow::GxMainWindow(QWidget *parent) :
    KMainWindow(parent), ui(setupUi())
{

    connect(ui->term,SIGNAL(finished()),this,SLOT(onTermFinished()));


}

GxMainWindow::~GxMainWindow()
{

    delete ui;
}

void GxMainWindow::onExecPressed()
{
    QString str = ui->cmdline->text() + "\n";
    ui->term->sendText(str);
}

void GxMainWindow::onActionaddNewItemTriggered()
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

void GxMainWindow::onActionnewProjectTriggered()
{
    this->ui->projtree->addProject();
}

void GxMainWindow::onProjtreeDoubleclicked(const QModelIndex &index)
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

void GxMainWindow::onActionaboutTriggered()
{
    this->showAboutApplication();
}

void GxMainWindow::onTermFinished()
{
    // start again
    KApplication::processEvents(QEventLoop::ExcludeUserInputEvents); // provide time for other signals to propagate data in case of parameter changes in the terminal (user keypresses/mouse does NOT do this)
    // timeslice up
    try
    {
        ui->term->startShellProgram();
    }
    catch(...)
    {
        QMessageBox::critical(this,"Critical","Cant restart the terminal, a critical error occurred!");
    }


}

void GxMainWindow::onActionCloseTriggered()
{
    if (ui->mdiArea->activeSubWindow() != NULL)
    {
        KTextEdit* win = boost::polymorphic_cast<KTextEdit*,QMdiSubWindow>(ui->mdiArea->activeSubWindow());
        if (ui->projtree->findBySubWindowLink(ui->mdiArea->activeSubWindow()).setOpen(false))
        {
            ui->mdiArea->removeSubWindow(win);
            delete win;
        }
    }
}
