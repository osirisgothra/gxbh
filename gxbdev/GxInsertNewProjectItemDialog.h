#ifndef GXINSERTNEWPROJECTITEMDIALOG_H
#define GXINSERTNEWPROJECTITEMDIALOG_H

#include <QDialog>
#include <QFile>
#include <QDir>


namespace Ui {
class GxInsertNewProjectItemDialog;
}

class GxInsertNewProjectItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GxInsertNewProjectItemDialog(QWidget *parent = 0);
    ~GxInsertNewProjectItemDialog();

    unsigned int getFilePermissions() const;
    QDir getFileTarget() const;
    QFile *getFileObject() const;
    QString getFileName() const;

private slots:
    // used directly in the ui file (it carries many connections and for this the ui was needed)

    void SetDialogItemStatuses();
    void SetFilePermissions();


private:
    bool fileSpecOkay();
    Ui::GxInsertNewProjectItemDialog *ui;    
    QString fileName;
    QFile* fileObject;
    QDir fileTarget;
    unsigned int filePermissions;    

};

#endif // GXINSERTNEWPROJECTITEMDIALOG_H
