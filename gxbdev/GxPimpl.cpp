// Private Implementation Code
// Nothing in here is meant to be changed on a regular basis, and is kept here
// to maintain ABI, protect code sequence, and hide hairy functions or other
// things that would otherwise be considered 'smelly code'.


#include "GxMainWindow.h"
#include "ui_GxMainWindow.h"

///
/// \brief GxMainWindow::setupUi
/// Brought to GxPimpl to preserve execution order of SetupUi
/// \return ui initialized, use only in the init list of the parent class
///
Ui::GxMainWindow* GxMainWindow::setupUi()
{
    Ui::GxMainWindow* rv = new Ui::GxMainWindow;
    rv->setupUi(this);
    return rv;
}
