#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T10:31:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = parseTransHistory
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += parsetransactions.h \
    transaction.h

SOURCES += main.cpp \          
    parsetransactions.cpp \
    transaction.cpp
