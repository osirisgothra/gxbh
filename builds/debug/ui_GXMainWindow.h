/********************************************************************************
** Form generated from reading UI file 'GXMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GXMAINWINDOW_H
#define UI_GXMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qtermwidget.h>

QT_BEGIN_NAMESPACE

class Ui_GXMainWindow
{
public:
    QAction *actionAbout;
    QAction *actionNew_Project;
    QAction *actionAdd_New_Item;
    QAction *actionAdd_Existing_Item;
    QAction *actionClose;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClear;
    QAction *actionRefresh;
    QAction *actionConfiguration;
    QAction *actionClose_2;
    QAction *actionClose_All;
    QAction *actionClose_Project;
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionTrace;
    QAction *actionTest_Current_Script;
    QAction *actionTest_Current_Function;
    QAction *actionTest_Block;
    QAction *actionTest_Selection;
    QAction *actionStop;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_View;
    QMenu *menu_Tools;
    QMenu *menu_Help;
    QMenu *menu_Window;
    QMenu *menuProject;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *projtree;
    QDockWidget *termpreview;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTermWidget *term;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *cmdline;
    QPushButton *exec;

    void setupUi(QMainWindow *GXMainWindow)
    {
        if (GXMainWindow->objectName().isEmpty())
            GXMainWindow->setObjectName(QString::fromUtf8("GXMainWindow"));
        GXMainWindow->resize(894, 711);
        actionAbout = new QAction(GXMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionNew_Project = new QAction(GXMainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionAdd_New_Item = new QAction(GXMainWindow);
        actionAdd_New_Item->setObjectName(QString::fromUtf8("actionAdd_New_Item"));
        actionAdd_Existing_Item = new QAction(GXMainWindow);
        actionAdd_Existing_Item->setObjectName(QString::fromUtf8("actionAdd_Existing_Item"));
        actionClose = new QAction(GXMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionCut = new QAction(GXMainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(GXMainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(GXMainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionClear = new QAction(GXMainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionRefresh = new QAction(GXMainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        actionConfiguration = new QAction(GXMainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        actionClose_2 = new QAction(GXMainWindow);
        actionClose_2->setObjectName(QString::fromUtf8("actionClose_2"));
        actionClose_All = new QAction(GXMainWindow);
        actionClose_All->setObjectName(QString::fromUtf8("actionClose_All"));
        actionClose_Project = new QAction(GXMainWindow);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        actionExit = new QAction(GXMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionStart = new QAction(GXMainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionTrace = new QAction(GXMainWindow);
        actionTrace->setObjectName(QString::fromUtf8("actionTrace"));
        actionTest_Current_Script = new QAction(GXMainWindow);
        actionTest_Current_Script->setObjectName(QString::fromUtf8("actionTest_Current_Script"));
        actionTest_Current_Function = new QAction(GXMainWindow);
        actionTest_Current_Function->setObjectName(QString::fromUtf8("actionTest_Current_Function"));
        actionTest_Block = new QAction(GXMainWindow);
        actionTest_Block->setObjectName(QString::fromUtf8("actionTest_Block"));
        actionTest_Selection = new QAction(GXMainWindow);
        actionTest_Selection->setObjectName(QString::fromUtf8("actionTest_Selection"));
        actionStop = new QAction(GXMainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        centralWidget = new QWidget(GXMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        horizontalLayout->addWidget(mdiArea);

        GXMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GXMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 894, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Tools = new QMenu(menuBar);
        menu_Tools->setObjectName(QString::fromUtf8("menu_Tools"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menu_Window = new QMenu(menuBar);
        menu_Window->setObjectName(QString::fromUtf8("menu_Window"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        GXMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GXMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GXMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GXMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GXMainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(GXMainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        projtree = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Project Item"));
        projtree->setHeaderItem(__qtreewidgetitem);
        new QTreeWidgetItem(projtree);
        projtree->setObjectName(QString::fromUtf8("projtree"));

        horizontalLayout_2->addWidget(projtree);

        dockWidget->setWidget(dockWidgetContents);
        GXMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        termpreview = new QDockWidget(GXMainWindow);
        termpreview->setObjectName(QString::fromUtf8("termpreview"));
        termpreview->setMinimumSize(QSize(212, 138));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        term = new QTermWidget(dockWidgetContents_2);
        term->setObjectName(QString::fromUtf8("term"));
        QFont font;
        term->setFont(font);
        term->setAutoFillBackground(false);
        term->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 0), stop:0.0773481 rgba(0, 0, 0, 255), stop:0.944751 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(213, 213, 213);"));

        verticalLayout->addWidget(term);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cmdline = new QLineEdit(dockWidgetContents_2);
        cmdline->setObjectName(QString::fromUtf8("cmdline"));

        horizontalLayout_3->addWidget(cmdline);

        exec = new QPushButton(dockWidgetContents_2);
        exec->setObjectName(QString::fromUtf8("exec"));

        horizontalLayout_3->addWidget(exec);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_4->addLayout(verticalLayout);

        termpreview->setWidget(dockWidgetContents_2);
        GXMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), termpreview);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Tools->menuAction());
        menuBar->addAction(menu_Window->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menu_File->addAction(actionNew_Project);
        menu_File->addSeparator();
        menu_File->addAction(actionAdd_New_Item);
        menu_File->addAction(actionAdd_Existing_Item);
        menu_File->addSeparator();
        menu_File->addAction(actionClose_2);
        menu_File->addAction(actionClose_All);
        menu_File->addAction(actionClose_Project);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menu_Edit->addAction(actionCut);
        menu_Edit->addAction(actionCopy);
        menu_Edit->addAction(actionPaste);
        menu_Edit->addAction(actionClear);
        menu_View->addAction(actionRefresh);
        menu_Tools->addAction(actionConfiguration);
        menu_Help->addAction(actionAbout);
        menu_Window->addAction(actionClose);
        menuProject->addAction(actionStart);
        menuProject->addAction(actionTest_Current_Script);
        menuProject->addAction(actionTest_Current_Function);
        menuProject->addAction(actionTest_Block);
        menuProject->addAction(actionTest_Selection);
        menuProject->addSeparator();
        menuProject->addAction(actionStop);

        retranslateUi(GXMainWindow);

        QMetaObject::connectSlotsByName(GXMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GXMainWindow)
    {
        GXMainWindow->setWindowTitle(QApplication::translate("GXMainWindow", "GXMainWindow", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("GXMainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setText(QApplication::translate("GXMainWindow", "New Project...", 0, QApplication::UnicodeUTF8));
        actionAdd_New_Item->setText(QApplication::translate("GXMainWindow", "Add New Item", 0, QApplication::UnicodeUTF8));
        actionAdd_Existing_Item->setText(QApplication::translate("GXMainWindow", "Add Existing Item", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("GXMainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("GXMainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("GXMainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("GXMainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("GXMainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        actionRefresh->setText(QApplication::translate("GXMainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        actionConfiguration->setText(QApplication::translate("GXMainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        actionClose_2->setText(QApplication::translate("GXMainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionClose_All->setText(QApplication::translate("GXMainWindow", "Close All", 0, QApplication::UnicodeUTF8));
        actionClose_Project->setText(QApplication::translate("GXMainWindow", "Close Project", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("GXMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("GXMainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionTrace->setText(QApplication::translate("GXMainWindow", "Trace", 0, QApplication::UnicodeUTF8));
        actionTest_Current_Script->setText(QApplication::translate("GXMainWindow", "Test Script", 0, QApplication::UnicodeUTF8));
        actionTest_Current_Function->setText(QApplication::translate("GXMainWindow", "Test Function", 0, QApplication::UnicodeUTF8));
        actionTest_Block->setText(QApplication::translate("GXMainWindow", "Test Block", 0, QApplication::UnicodeUTF8));
        actionTest_Selection->setText(QApplication::translate("GXMainWindow", "Test Selection", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("GXMainWindow", "All Stop", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("GXMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("GXMainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("GXMainWindow", "&View", 0, QApplication::UnicodeUTF8));
        menu_Tools->setTitle(QApplication::translate("GXMainWindow", "&Tools", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("GXMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menu_Window->setTitle(QApplication::translate("GXMainWindow", "&Window", 0, QApplication::UnicodeUTF8));
        menuProject->setTitle(QApplication::translate("GXMainWindow", "Project", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("GXMainWindow", "Project Explorer", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = projtree->isSortingEnabled();
        projtree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = projtree->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("GXMainWindow", "Untitled", 0, QApplication::UnicodeUTF8));
        projtree->setSortingEnabled(__sortingEnabled);

        termpreview->setWindowTitle(QApplication::translate("GXMainWindow", "Script Test Area", 0, QApplication::UnicodeUTF8));
        exec->setText(QApplication::translate("GXMainWindow", "Test With Parameters", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GXMainWindow: public Ui_GXMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GXMAINWINDOW_H
