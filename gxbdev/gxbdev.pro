

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gxbdev
TEMPLATE = app

LIBS += -lX1164 -lutil -lqtermwidget -lkdeui -lkio

SOURCES += main.cpp\
        GxMainWindow.cpp \
    GxEditorWindow.cpp \
    GxProjectTree.cpp \
    GxProjectItem.cpp \
    GxCreateProjectWindow.cpp

HEADERS  += GxMainWindow.h \
    GxEditorWindow.h \
    GxProjectTree.h \
    GxProjectItem.h \
    GxCreateProjectWindow.h

FORMS    += GxMainWindow.ui \
    GxCreateProjectWindow.ui

INCLUDEPATH += /src/r
