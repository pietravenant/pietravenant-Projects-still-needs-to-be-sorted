QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A3Project
TEMPLATE = app

SOURCES += main.cpp\
        mymainwindow.cpp \
    itemdialog.cpp \
    item.cpp \
    itemlist.cpp \
    itemreader.cpp \
    itemwriter.cpp

HEADERS  += mymainwindow.h \
    itemdialog.h \
    item.h \
    itemlist.h \
    itemreader.h \
    itemwriter.h
