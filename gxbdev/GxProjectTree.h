#ifndef GXPROJECTTREE_H
#define GXPROJECTTREE_H

#include <QtCore>
#include <QtGui>

class GxProjectItem;
class Ui_GxMainWindow;

class GxProjectTree : public QTreeWidget
{
    Q_OBJECT
    friend class GxProjectItem;

public:
    explicit GxProjectTree(QWidget *parent = 0);

    // in a matter of speaking, a gxprojectitem
    // is any toplevel item
    int AddProject();
    int SelectedProject(void);
    int ProjectCount(void);

    const GxProjectItem& GetProject(int pos);


signals:

public slots:

private:
    // hidden methods, perhaps can be accessed but not by accident




};

#endif // GXPROJECTTREE_H
