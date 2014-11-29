#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T00:47:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    arithmetic.cpp \
    calculator.cpp

HEADERS  += dialog.h \
    arithmetic.h \
    calculator.h

FORMS    += dialog.ui

CONFIG += static

QTPLUGIN += qsqloci qgif
