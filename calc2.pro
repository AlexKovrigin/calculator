#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T17:26:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calc2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    null.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    null.h \
    buttonsreference.h

FORMS    += mainwindow.ui \
    dialog.ui \
    null.ui
