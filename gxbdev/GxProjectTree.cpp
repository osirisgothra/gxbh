#include "GxProjectTree.h"

#define GXPRJ_DATACOLUMN    2
#define GXPRJ_DATAROLE      Qt::UserRole
///
/// \brief __bi2pi
/// \param ti tree item to work with
/// \param pi (if NULL) causes __bi2pi to try to extract a GxProjectItem from the item specified by ``ti''
/// \param pi (if not NULL) the GxProjectItem to bind to the tree item specified by ``ti''
/// \return the project item bound to ``ti'' if any, when ``pi'' is not NULL, and a ``pi'' is already present and/or a different object, returns the old object being replaced
/// \note internal use only, does not delete any pointers even if replacing, \sa __delete_twpi
GxProjectItem* __bi2pi(QTreeWidgetItem* ti, GxProjectItem* pi = NULL)
{
    QVariant usrdata = ti->data(GXPRJ_DATACOLUMN,GXPRJ_DATAROLE);
    GxProjectItem* retval = (GxProjectItem*) usrdata.value<void*>();

    if (pi != NULL)
    {
        QVariant setdata = QVariant::fromValue<void*>((void*)pi);
        ti->setData(GXPRJ_DATACOLUMN,GXPRJ_DATAROLE,setdata);

    }
    return retval;
}


GxProjectTree::GxProjectTree(QWidget *parent) :
    QTreeWidget(parent)
{
    // create the project as empty
    QTreeWidgetItem* root_twi = new QTreeWidgetItem();
    GxProjectItem* root_pji = new GxProjectItem("Untitled",this,root_twi);
    __bi2pi(root_twi,root_pji);
    insertTopLevelItem(0,root_twi);

}


GxProjectItem::GxProjectItem(QString name, GxProjectTree *owner, QTreeWidgetItem *parentitem)
{

}
