#include "GxCreateProjectWindow.h"
#include "ui_GxCreateProjectWindow.h"

GxCreateProjectWindow::GxCreateProjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GxCreateProjectWindow)
{
    ui->setupUi(this);

    // replace the KEditListBox's editor witha KUrlRequester
    // because of QtCreator, we had to do this manually
    KUrlRequester* req = new KUrlRequester();
    ui->epi->setCustomEditor(req->customEditor());
}

GxCreateProjectWindow::~GxCreateProjectWindow()
{
    delete ui;
}
