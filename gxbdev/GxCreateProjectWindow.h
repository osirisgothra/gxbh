#ifndef GXCREATEPROJECTWINDOW_H
#define GXCREATEPROJECTWINDOW_H

#include <QDialog>
class GxProjectTree;

namespace Ui {
class GxCreateProjectWindow;
}

class GxCreateProjectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GxCreateProjectWindow(QWidget *parent = 0);
    ~GxCreateProjectWindow();

    friend class GxProjectTree;

    QString projectFilename;
    QString projectDispname;
    QStringList projectItems;
    bool projectWantItems;

protected:
    Ui::GxCreateProjectWindow *ui;
private slots:
    void on_epi_added(const QString &text);
    void checkControls();

};

#endif // GXCREATEPROJECTWINDOW_H
