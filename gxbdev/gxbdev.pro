



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gxbdev
TEMPLATE = app

QMAKE_CXX = g++-4.7


LIBS += -lX1164 -lutil -lqtermwidget -lkdeui -lkio -lboost_filesystem -lboost_system -lkdecore

SOURCES +=\
        GxMainWindow.cpp \
    GxEditorWindow.cpp \
    GxProjectTree.cpp \
    GxProjectItem.cpp \
    GxCreateProjectWindow.cpp \
    GxDevException.cpp \
    GxSyntaxHighlighter.cpp \
    GxApplication.cpp \
    GxPimpl.cpp \
    GxConfigManagement.cpp \
    GxInsertNewProjectItemDialog.cpp \
    GxWebView.cpp

HEADERS  += GxMainWindow.h \
    GxEditorWindow.h \
    GxProjectTree.h \
    GxProjectItem.h \
    GxCreateProjectWindow.h \
    GxDevException.h \
    GxSyntaxHighlighter.h \
    GxApplication.h \
    GxConfigManagement.h \
    GxInsertNewProjectItemDialog.h \
    GxWebView.h

FORMS    += GxMainWindow.ui \
    GxCreateProjectWindow.ui \
    GxInsertNewProjectItemDialog.ui \
    GxWebView.ui

