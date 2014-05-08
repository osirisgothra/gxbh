#ifndef GXMAINWINDOW_H
#define GXMAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class GXMainWindow;
}


class GXMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GXMainWindow(QWidget *parent = 0);
    ~GXMainWindow();

private slots:
    void on_exec_pressed();
    void on_actionAdd_New_Item_triggered();


private:
    QList<QTextDocument*> open_documents;

    Ui::GXMainWindow *ui;
};

#endif // GXMAINWINDOW_H
