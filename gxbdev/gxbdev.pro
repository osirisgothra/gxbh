#-------------------------------------------------
#
# Project created by QtCreator 2014-05-06T18:25:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gxbdev
TEMPLATE = app

LIBS += -lX1164 -lutil -lqtermwidget

SOURCES += main.cpp\
        GXMainWindow.cpp \
    terminal.cpp \
    GxEditorWindow.cpp \
    GxProjectTree.cpp

HEADERS  += GXMainWindow.h \
    terminal.h \
    GxEditorWindow.h \
    GxProjectTree.h

FORMS    += GXMainWindow.ui
