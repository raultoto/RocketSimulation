#-------------------------------------------------
#
# Project created by QtCreator 2017-06-25T09:53:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RocketSimulation
TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp \
    rocket.cpp \
    earth.cpp \
    environment.cpp \
    menu.cpp \
    rocketinterface.cpp \
    earthinterface.cpp \
    showdata.cpp \
    rockettrajectory.cpp \
    background.cpp \
    button.cpp \
    vectores.cpp \
    movementheight.cpp \
    graphdata.cpp

HEADERS  += \
    rocket.h \
    earth.h \
    environment.h \
    menu.h \
    rocketinterface.h \
    earthinterface.h \
    showdata.h \
    rockettrajectory.h \
    background.h \
    button.h \
    vectores.h \
    movementheight.h \
    graphdata.h \
    datos_iniciales.h

FORMS    +=

RESOURCES += \
    res.qrc
