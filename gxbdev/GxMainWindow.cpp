#include "GxApplication.h"
#include "GxProjectItem.h"
#include "GxProjectTree.h"
#include "GxMainWindow.h"
#include <qtermwidget.h>
#include "ui_GxMainWindow.h"
#include <QtGui>
#include <QtCore>
#include <KDE/KTextEdit>
#include <KDE/KMainWindow>
#include <KDE/KApplication>
#include <KDE/KHelpMenu>
#include <boost/cast.hpp>
#include <QMap>
#include <QDockWidget>
#include "GxSyntaxHighlighter.h"


GxMainWindow::GxMainWindow(QWidget *parent) :
    KMainWindow(parent)
{
    ui = new Ui::GxMainWindow;
    ui->setupUi(this);

    connect(ui->term,SIGNAL(finished()),this,SLOT(onTermFinished()));
    connect(ui->actionNew_Project,SIGNAL(triggered()),this,SLOT(onActionnewProjectTriggered()));

    // depending on the user's preference (kde settings that is)
    // will set click preferences to this, since it is the one mouse
    // behavior that does not happen automatically (like focus, hover, etc)
    // if its not present it will fail back to double-click navigation mode
    if (GxApplication::instance()->config->singleClick())
    {
        qDebug() << "Using Single-Click Navigation Mode";
        connect(ui->projtree,SIGNAL(clicked(QModelIndex)),this,SLOT(onProjtreeDoubleclicked(QModelIndex)));
    }
    else
    {
        qDebug() << "Using Double-Click Navigation Mode";
        connect(ui->projtree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onProjtreeDoubleclicked(QModelIndex)));
    }

    ui->syntaxDock->setFloating(false);
    tabifyDockWidget(ui->projectsDock,ui->syntaxDock);

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
    if (ui->projtree->selectedProject() >= 0)
    {
        bool pressed = false;

        if (pressed)
        {

        }
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

void GxMainWindow::on_sh_apply_clicked()
{
    if (ui->mdiArea->activeSubWindow() != NULL)
    {
        KTextEdit* win = boost::polymorphic_cast<KTextEdit*,QMdiSubWindow>(ui->mdiArea->activeSubWindow());
        GxSyntaxHighlighter* highlighter = win->document()->findChild<GxSyntaxHighlighter*>();


    }

}
