#include "GXMainWindow.h"
#include "terminal.h"
#include <qtermwidget.h>
#include "ui_GXMainWindow.h"
#include <QtGui>
#include <QtCore>

GXMainWindow::GXMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GXMainWindow)
{
    ui->setupUi(this);
    QApplication::processEvents();




}

GXMainWindow::~GXMainWindow()
{
    delete ui;
}

void GXMainWindow::on_exec_pressed()
{
    QString txt = "/gxbase/gxbase\n";
    ui->term->sendText(txt);
}

void GXMainWindow::on_actionAdd_New_Item_triggered()
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
        QTextDocument* newdoc = new QTextDocument(this);
        newdoc->setMetaInformation(QTextDocument::DocumentTitle,docname);
        // add to project


    }

}
