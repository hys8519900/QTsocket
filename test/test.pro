#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T16:54:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
    finddialog.cpp \
    basesocket.cpp \
    mainwindow.cpp \
    eventlabel.cpp \
    paintedwidget.cpp \
    mysocket.cpp \
    getpicfromurl.cpp

HEADERS  += \
    finddialog.h \
    winsock.h \
    basesocket.h \
    mainwindow.h \
    eventlabel.h \
    paintedwidget.h \
    mysocket.h \
    note.h \
    getpicfromurl.h

LIBS += -lwsock32

RESOURCES += \
    res.qrc
