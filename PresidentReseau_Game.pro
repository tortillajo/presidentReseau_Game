#-------------------------------------------------
#
# Project created by QtCreator 2013-02-11T20:46:03
#
#-------------------------------------------------


#QT       += core gui
#QT       += widgets
#QT       += gui declarative
#CONFIG   += qt gui
CONFIG   += core
QT       += network
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PresidentReseau_Game
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    serverwindow.cpp \
    client.cpp

HEADERS  += \
    mainwindow.hpp \
    serverwindow.hpp \
    client.hpp

FORMS    +=
