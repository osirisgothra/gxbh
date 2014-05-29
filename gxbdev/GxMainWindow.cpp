#include "GxMainWindow.h"
#include <qtermwidget.h>
#include "ui_GxMainWindow.h"
#include <QtGui>
#include <QtCore>
#include "GxProjectItem.h"
#include "GxProjectTree.h"


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
        // add to project



    }

}

void GxMainWindow::on_actionNew_Project_triggered()
{
    this->ui->projtree->AddProject();
}
