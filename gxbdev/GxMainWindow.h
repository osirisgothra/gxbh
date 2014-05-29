#ifndef GXMAINWINDOW_H
#define GXMAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class GxMainWindow;
}


class GxMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GxMainWindow(QWidget *parent = 0);
    ~GxMainWindow();

private slots:
    void on_exec_pressed();
    void on_actionAdd_New_Item_triggered();


    void on_actionNew_Project_triggered();

private:
    QList<QTextDocument*> open_documents;

    Ui::GxMainWindow *ui;
};

#endif // GXMAINWINDOW_H
