#ifndef GXMAINWINDOW_H
#define GXMAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <KDE/KMainWindow>
namespace Ui {
class GxMainWindow;
}


class GxMainWindow : public KMainWindow
{
    Q_OBJECT

public:
    explicit GxMainWindow(QWidget *parent = 0);
    ~GxMainWindow();
    QLineEdit* line;
    QAction* lineAction;

private slots:
    void onExecPressed();
    void onActionaddNewItemTriggered();
    void onActionnewProjectTriggered();
    void onProjtreeDoubleclicked(const QModelIndex &index);
    void onActionaboutTriggered();
    void onTermFinished();



    void onActionCloseTriggered();

    void on_sh_apply_clicked();

private:
    QList<QTextDocument*> open_documents;

    Ui::GxMainWindow *ui;
    Ui::GxMainWindow *setupUi(); // ensure ui setup happens first (prevents any possibility otherwise)

};

#endif // GXMAINWINDOW_H
