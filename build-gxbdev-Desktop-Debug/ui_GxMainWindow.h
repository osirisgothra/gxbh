/********************************************************************************
** Form generated from reading UI file 'GxMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GXMAINWINDOW_H
#define UI_GXMAINWINDOW_H

#include <GxProjectTree.h>
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qtermwidget.h>

QT_BEGIN_NAMESPACE

class Ui_GxMainWindow
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
    QAction *actionSave_Project;
    QAction *actionSave_Project_As;
    QAction *actionSave_Document;
    QAction *actionSave_Document_As;
    QAction *actionSet_Active;
    QAction *actionUnload;
    QAction *actionDelete;
    QAction *actionReload;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSave_All;
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
    GxProjectTree *projtree;
    QDockWidget *termpreview;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTermWidget *term;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *cmdline;
    QPushButton *exec;

    void setupUi(QMainWindow *GxMainWindow)
    {
        if (GxMainWindow->objectName().isEmpty())
            GxMainWindow->setObjectName(QString::fromUtf8("GxMainWindow"));
        GxMainWindow->resize(894, 711);
        actionAbout = new QAction(GxMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("help-about");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAbout->setIcon(icon);
        actionNew_Project = new QAction(GxMainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Project->setIcon(icon1);
        actionAdd_New_Item = new QAction(GxMainWindow);
        actionAdd_New_Item->setObjectName(QString::fromUtf8("actionAdd_New_Item"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("project-development-new-template");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAdd_New_Item->setIcon(icon2);
        actionAdd_Existing_Item = new QAction(GxMainWindow);
        actionAdd_Existing_Item->setObjectName(QString::fromUtf8("actionAdd_Existing_Item"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAdd_Existing_Item->setIcon(icon3);
        actionClose = new QAction(GxMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("document-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose->setIcon(icon4);
        actionCut = new QAction(GxMainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon5);
        actionCopy = new QAction(GxMainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon6);
        actionPaste = new QAction(GxMainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon7);
        actionClear = new QAction(GxMainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("edit-clear");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClear->setIcon(icon8);
        actionRefresh = new QAction(GxMainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("reload");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRefresh->setIcon(icon9);
        actionConfiguration = new QAction(GxMainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("configure");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionConfiguration->setIcon(icon10);
        actionClose_2 = new QAction(GxMainWindow);
        actionClose_2->setObjectName(QString::fromUtf8("actionClose_2"));
        actionClose_2->setIcon(icon4);
        actionClose_All = new QAction(GxMainWindow);
        actionClose_All->setObjectName(QString::fromUtf8("actionClose_All"));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("project-development-close-all");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose_All->setIcon(icon11);
        actionClose_Project = new QAction(GxMainWindow);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        QIcon icon12;
        iconThemeName = QString::fromUtf8("project-development-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose_Project->setIcon(icon12);
        actionExit = new QAction(GxMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon13;
        iconThemeName = QString::fromUtf8("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon13 = QIcon::fromTheme(iconThemeName);
        } else {
            icon13.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon13);
        actionStart = new QAction(GxMainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon14;
        iconThemeName = QString::fromUtf8("debug-run");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon14 = QIcon::fromTheme(iconThemeName);
        } else {
            icon14.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionStart->setIcon(icon14);
        actionTrace = new QAction(GxMainWindow);
        actionTrace->setObjectName(QString::fromUtf8("actionTrace"));
        QIcon icon15;
        iconThemeName = QString::fromUtf8("debug-step-into");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon15 = QIcon::fromTheme(iconThemeName);
        } else {
            icon15.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTrace->setIcon(icon15);
        actionTest_Current_Script = new QAction(GxMainWindow);
        actionTest_Current_Script->setObjectName(QString::fromUtf8("actionTest_Current_Script"));
        QIcon icon16;
        iconThemeName = QString::fromUtf8("quickopen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon16 = QIcon::fromTheme(iconThemeName);
        } else {
            icon16.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest_Current_Script->setIcon(icon16);
        actionTest_Current_Function = new QAction(GxMainWindow);
        actionTest_Current_Function->setObjectName(QString::fromUtf8("actionTest_Current_Function"));
        QIcon icon17;
        iconThemeName = QString::fromUtf8("quickopen-function");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon17 = QIcon::fromTheme(iconThemeName);
        } else {
            icon17.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest_Current_Function->setIcon(icon17);
        actionTest_Block = new QAction(GxMainWindow);
        actionTest_Block->setObjectName(QString::fromUtf8("actionTest_Block"));
        QIcon icon18;
        iconThemeName = QString::fromUtf8("quickopen-class");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon18 = QIcon::fromTheme(iconThemeName);
        } else {
            icon18.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest_Block->setIcon(icon18);
        actionTest_Selection = new QAction(GxMainWindow);
        actionTest_Selection->setObjectName(QString::fromUtf8("actionTest_Selection"));
        QIcon icon19;
        iconThemeName = QString::fromUtf8("quickopen-file");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon19 = QIcon::fromTheme(iconThemeName);
        } else {
            icon19.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest_Selection->setIcon(icon19);
        actionStop = new QAction(GxMainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon20;
        iconThemeName = QString::fromUtf8("process-stop");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon20 = QIcon::fromTheme(iconThemeName);
        } else {
            icon20.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionStop->setIcon(icon20);
        actionSave_Project = new QAction(GxMainWindow);
        actionSave_Project->setObjectName(QString::fromUtf8("actionSave_Project"));
        QIcon icon21;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon21 = QIcon::fromTheme(iconThemeName);
        } else {
            icon21.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_Project->setIcon(icon21);
        actionSave_Project_As = new QAction(GxMainWindow);
        actionSave_Project_As->setObjectName(QString::fromUtf8("actionSave_Project_As"));
        QIcon icon22;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon22 = QIcon::fromTheme(iconThemeName);
        } else {
            icon22.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_Project_As->setIcon(icon22);
        actionSave_Document = new QAction(GxMainWindow);
        actionSave_Document->setObjectName(QString::fromUtf8("actionSave_Document"));
        actionSave_Document->setEnabled(false);
        actionSave_Document->setIcon(icon21);
        actionSave_Document_As = new QAction(GxMainWindow);
        actionSave_Document_As->setObjectName(QString::fromUtf8("actionSave_Document_As"));
        actionSave_Document_As->setEnabled(false);
        actionSave_Document_As->setIcon(icon22);
        actionSet_Active = new QAction(GxMainWindow);
        actionSet_Active->setObjectName(QString::fromUtf8("actionSet_Active"));
        actionUnload = new QAction(GxMainWindow);
        actionUnload->setObjectName(QString::fromUtf8("actionUnload"));
        actionDelete = new QAction(GxMainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionReload = new QAction(GxMainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        actionSave = new QAction(GxMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(GxMainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_All = new QAction(GxMainWindow);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        centralWidget = new QWidget(GxMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        horizontalLayout->addWidget(mdiArea);

        GxMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GxMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 894, 21));
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
        GxMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GxMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GxMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GxMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GxMainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(GxMainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        projtree = new GxProjectTree(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Project Item"));
        projtree->setHeaderItem(__qtreewidgetitem);
        projtree->setObjectName(QString::fromUtf8("projtree"));
        projtree->setContextMenuPolicy(Qt::CustomContextMenu);
        projtree->setUniformRowHeights(true);
        projtree->setAnimated(true);
        projtree->setHeaderHidden(true);
        projtree->header()->setVisible(false);
        projtree->header()->setHighlightSections(false);

        horizontalLayout_2->addWidget(projtree);

        dockWidget->setWidget(dockWidgetContents);
        GxMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        termpreview = new QDockWidget(GxMainWindow);
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
        GxMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), termpreview);

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
        menu_File->addAction(actionSave_Project);
        menu_File->addAction(actionSave_Project_As);
        menu_File->addAction(actionSave_Document);
        menu_File->addAction(actionSave_Document_As);
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
        mainToolBar->addAction(actionNew_Project);
        mainToolBar->addAction(actionAdd_New_Item);
        mainToolBar->addAction(actionAdd_Existing_Item);
        mainToolBar->addAction(actionSave_Project);
        mainToolBar->addAction(actionClose_All);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addAction(actionClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionTrace);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTest_Current_Script);
        mainToolBar->addAction(actionTest_Current_Function);
        mainToolBar->addAction(actionTest_Block);
        mainToolBar->addAction(actionTest_Selection);
        mainToolBar->addAction(actionStop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addAction(actionConfiguration);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);

        retranslateUi(GxMainWindow);

        QMetaObject::connectSlotsByName(GxMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GxMainWindow)
    {
        GxMainWindow->setWindowTitle(QApplication::translate("GxMainWindow", "GxMainWindow", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("GxMainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("GxMainWindow", "Shift+F1", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setText(QApplication::translate("GxMainWindow", "New Project...", 0, QApplication::UnicodeUTF8));
        actionAdd_New_Item->setText(QApplication::translate("GxMainWindow", "Add New Item", 0, QApplication::UnicodeUTF8));
        actionAdd_Existing_Item->setText(QApplication::translate("GxMainWindow", "Add Existing Item", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("GxMainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("GxMainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("GxMainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("GxMainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("GxMainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        actionRefresh->setText(QApplication::translate("GxMainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        actionConfiguration->setText(QApplication::translate("GxMainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        actionClose_2->setText(QApplication::translate("GxMainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionClose_All->setText(QApplication::translate("GxMainWindow", "Close All", 0, QApplication::UnicodeUTF8));
        actionClose_Project->setText(QApplication::translate("GxMainWindow", "Close Project", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("GxMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("GxMainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionTrace->setText(QApplication::translate("GxMainWindow", "Trace", 0, QApplication::UnicodeUTF8));
        actionTest_Current_Script->setText(QApplication::translate("GxMainWindow", "Test Script", 0, QApplication::UnicodeUTF8));
        actionTest_Current_Function->setText(QApplication::translate("GxMainWindow", "Test Function", 0, QApplication::UnicodeUTF8));
        actionTest_Block->setText(QApplication::translate("GxMainWindow", "Test Block", 0, QApplication::UnicodeUTF8));
        actionTest_Selection->setText(QApplication::translate("GxMainWindow", "Test Selection", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("GxMainWindow", "All Stop", 0, QApplication::UnicodeUTF8));
        actionSave_Project->setText(QApplication::translate("GxMainWindow", "Save Project", 0, QApplication::UnicodeUTF8));
        actionSave_Project_As->setText(QApplication::translate("GxMainWindow", "Save Project As...", 0, QApplication::UnicodeUTF8));
        actionSave_Document->setText(QApplication::translate("GxMainWindow", "Save Active Document", 0, QApplication::UnicodeUTF8));
        actionSave_Document_As->setText(QApplication::translate("GxMainWindow", "Save Active Document As...", 0, QApplication::UnicodeUTF8));
        actionSet_Active->setText(QApplication::translate("GxMainWindow", "Set Active", 0, QApplication::UnicodeUTF8));
        actionUnload->setText(QApplication::translate("GxMainWindow", "Unload", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("GxMainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        actionReload->setText(QApplication::translate("GxMainWindow", "Reload", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("GxMainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("GxMainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionSave_All->setText(QApplication::translate("GxMainWindow", "Save All", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("GxMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("GxMainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("GxMainWindow", "&View", 0, QApplication::UnicodeUTF8));
        menu_Tools->setTitle(QApplication::translate("GxMainWindow", "&Tools", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("GxMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menu_Window->setTitle(QApplication::translate("GxMainWindow", "&Window", 0, QApplication::UnicodeUTF8));
        menuProject->setTitle(QApplication::translate("GxMainWindow", "Project", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("GxMainWindow", "Project Explorer", 0, QApplication::UnicodeUTF8));
        termpreview->setWindowTitle(QApplication::translate("GxMainWindow", "Script Test Area", 0, QApplication::UnicodeUTF8));
        exec->setText(QApplication::translate("GxMainWindow", "Test With Parameters", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GxMainWindow: public Ui_GxMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GXMAINWINDOW_H
