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
protected:
    Ui::GxCreateProjectWindow *ui;
};

#endif // GXCREATEPROJECTWINDOW_H
