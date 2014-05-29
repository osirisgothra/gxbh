/********************************************************************************
** Form generated from reading UI file 'GxCreateProjectWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GXCREATEPROJECTWINDOW_H
#define UI_GXCREATEPROJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include "keditlistbox.h"
#include "klineedit.h"
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

class Ui_GxCreateProjectWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *projectFileLabel;
    KUrlRequester *projectFile;
    QLabel *projectNameLabel;
    KLineEdit *projectName;
    QLabel *projectNameLabel_2;
    KEditListBox *epi;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GxCreateProjectWindow)
    {
        if (GxCreateProjectWindow->objectName().isEmpty())
            GxCreateProjectWindow->setObjectName(QString::fromUtf8("GxCreateProjectWindow"));
        GxCreateProjectWindow->resize(607, 513);
        verticalLayout = new QVBoxLayout(GxCreateProjectWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(GxCreateProjectWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        projectFileLabel = new QLabel(groupBox);
        projectFileLabel->setObjectName(QString::fromUtf8("projectFileLabel"));

        verticalLayout_2->addWidget(projectFileLabel);

        projectFile = new KUrlRequester(groupBox);
        projectFile->setObjectName(QString::fromUtf8("projectFile"));

        verticalLayout_2->addWidget(projectFile);

        projectNameLabel = new QLabel(groupBox);
        projectNameLabel->setObjectName(QString::fromUtf8("projectNameLabel"));

        verticalLayout_2->addWidget(projectNameLabel);

        projectName = new KLineEdit(groupBox);
        projectName->setObjectName(QString::fromUtf8("projectName"));

        verticalLayout_2->addWidget(projectName);

        projectNameLabel_2 = new QLabel(groupBox);
        projectNameLabel_2->setObjectName(QString::fromUtf8("projectNameLabel_2"));

        verticalLayout_2->addWidget(projectNameLabel_2);

        epi = new KEditListBox(groupBox);
        epi->setObjectName(QString::fromUtf8("epi"));

        verticalLayout_2->addWidget(epi);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(GxCreateProjectWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GxCreateProjectWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), GxCreateProjectWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GxCreateProjectWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(GxCreateProjectWindow);
    } // setupUi

    void retranslateUi(QDialog *GxCreateProjectWindow)
    {
        GxCreateProjectWindow->setWindowTitle(QApplication::translate("GxCreateProjectWindow", "Create New Project", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GxCreateProjectWindow", "Set Up Project Details", 0, QApplication::UnicodeUTF8));
        projectFileLabel->setText(QApplication::translate("GxCreateProjectWindow", "Project File Location", 0, QApplication::UnicodeUTF8));
        projectFile->setClickMessage(QApplication::translate("GxCreateProjectWindow", "Please Select a Filename and Location", 0, QApplication::UnicodeUTF8));
        projectNameLabel->setText(QApplication::translate("GxCreateProjectWindow", "Project Name (Used Internally)", 0, QApplication::UnicodeUTF8));
        projectName->setClickMessage(QApplication::translate("GxCreateProjectWindow", "Project Name", 0, QApplication::UnicodeUTF8));
        projectNameLabel_2->setText(QApplication::translate("GxCreateProjectWindow", "Initial Project Items (Optional)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GxCreateProjectWindow: public Ui_GxCreateProjectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GXCREATEPROJECTWINDOW_H
