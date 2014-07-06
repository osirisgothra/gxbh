#include "GxInsertNewProjectItemDialog.h"
#include "ui_GxInsertNewProjectItemDialog.h"
#include <boost/filesystem.hpp>
#include <boost/cast.hpp>

using namespace std;
using namespace boost::filesystem;

GxInsertNewProjectItemDialog::GxInsertNewProjectItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GxInsertNewProjectItemDialog)
{
    ui->setupUi(this);        
    fileObject = NULL;
    fileName = "";
    fileTarget = QDir::current();
    filePermissions = 0x10000;
}

GxInsertNewProjectItemDialog::~GxInsertNewProjectItemDialog()
{
    delete ui;
}

void GxInsertNewProjectItemDialog::SetDialogItemStatuses()
{

    bool sOk = fileSpecOkay();
    // check okay-ness
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(sOk);


}

void GxInsertNewProjectItemDialog::SetFilePermissions()
{
    unsigned int mask = 0x10000;    // 0x10000 = file   0x40000 = dir

    mask |= (ui->o_x->isChecked())? 0x1 :0;
    mask |= (ui->o_w->isChecked())? 0x2 :0;
    mask |= (ui->o_r->isChecked())? 0x4 :0;
    mask |= (ui->g_x->isChecked())? 0x10 :0;
    mask |= (ui->g_x->isChecked())? 0x20 :0;
    mask |= (ui->g_x->isChecked())? 0x40 :0;
    mask |= (ui->u_x->isChecked())? 0x100 :0;
    mask |= (ui->u_x->isChecked())? 0x200 :0;
    mask |= (ui->u_x->isChecked())? 0x400 :0;
    mask |= (ui->a_s->isChecked())? 0x1000 :0;
    mask |= (ui->g_s->isChecked())? 0x2000 :0;
    mask |= (ui->u_s->isChecked())? 0x4000 :0;

    filePermissions = mask;

}

bool GxInsertNewProjectItemDialog::fileSpecOkay()
{
    string filename = fileName.toStdString();

    path target(filename);
    target = target.remove_filename();
    target = target.branch_path();

    if (portable_directory_name(target))
    {
        fileTarget.setPath(QString::fromStdString(target.string()));
    }

    
    fileTarget.setPath();
    if (fileObject)
    {
        fileObject->close();
        fileObject->remove();
        delete fileObject;
    }
    fileObject = new QFile(fileTarget.canonicalPath(fileName),this);
    if (fileObject->exists())
        return false;       // cant already exist
    else
    {
        char stripe[] = { "stripe" };
        QFile::Permission perm = (QFile::Permission)filePermissions;
        if (( fileObject->setPermissions(perm) &&
              fileObject->open(QFile::ReadWrite) &&
              fileObject->write(stripe) &&
              fileObject->close()
           ))
        {
            return true;
        }
    }

}
QString GxInsertNewProjectItemDialog::getFileName() const
{
    return fileName;
}

QFile* GxInsertNewProjectItemDialog::getFileObject() const
{
    return fileObject;
}

QDir GxInsertNewProjectItemDialog::getFileTarget() const
{
    return fileTarget;
}


unsigned int GxInsertNewProjectItemDialog::getFilePermissions() const
{
    return filePermissions;
}
