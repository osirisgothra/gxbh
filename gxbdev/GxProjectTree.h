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
    int addProject();
    int selectedProject(void);
    int projectCount(void);

    GxProjectItem &findBySubWindowLink(QMdiSubWindow* link);

    GxProjectItem &getProject(int pos);
    GxProjectItem &projectItemFromIndex(const QModelIndex& index);

signals:

public slots:

private:
    // hidden methods, perhaps can be accessed but not by accident




};

#endif // GXPROJECTTREE_H
