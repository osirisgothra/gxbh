#include "GxCreateProjectWindow.h"
#include "ui_GxCreateProjectWindow.h"
#include <QMessageBox>
#include <QListView>
#include <QFileInfo>
#include <QInputDialog>


GxCreateProjectWindow::GxCreateProjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GxCreateProjectWindow)
{
    ui->setupUi(this);
    KUrlRequester* req = new KUrlRequester(this);
    req->setClickMessage("Type a Filename or a Wildcard Expression");
    ui->epi->setCustomEditor(req->customEditor());

}

GxCreateProjectWindow::~GxCreateProjectWindow()
{
    delete ui;
}

void GxCreateProjectWindow::on_epi_added(const QString &text)
{
    QString txt = text;
    QString filter = "*";
    QDir dir(text);
    QStringList items = ui->epi->items();
    bool skip = false;


    if (dir.exists(text))
    {
        if (QMessageBox::question(this,text,"This is a directory, add all from this path",QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        {
            if (QMessageBox::question(this,text,"Press YES if you want to specify a filter to look for files, or press ABORT to cancel the operation (paths can NOT be added as items)",QMessageBox::Yes | QMessageBox::Abort) == QMessageBox::Yes)
            {
                filter = QInputDialog::getText(this,tr("Input Required"),tr("Filter:"),QLineEdit::Normal,filter,&skip);
                skip ^= true; // getText sets this true if ok, so invert it (skip xor 0x00000001)
            }
            else
                skip = true;
        }

        if (!skip)
        {
        QStringList diritems = dir.entryList(QStringList(filter),QDir::Files,QDir::Name);
            if (!diritems.isEmpty())
            {
                QString prepend = text;
                if (!text.endsWith("/"))
                    prepend += '/';

                foreach (QString str, diritems)
                {
                    QString nextitem = prepend + str;
                    items.append(nextitem);
                }
            }
            else
                QMessageBox::warning(this,"Warning","No files in this directory");
        }

    }
    else if (QFile::exists(text))
    {
        // dont do first because dirs count as files
        return;
    }

    // if the item was not a file, we still need to remove it


    for (int i = 0; i < items.count(); i++)
    {
        if (items.at(i) == text)
        {
            // got the index
            items.removeAt(i);
            break; // since no more could possibly match
        }
    }
    ui->epi->setItems(items);


}
