TEMPLATE = app
TARGET = erni_qt

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += ./inc

SOURCES += src/main.cpp \
    src/calculationcontroller.cpp \
    src/calculationmodel.cpp \
    src/window.cpp

HEADERS += \
    inc/calculationcontroller.h \
    inc/calculationmodel.h \
    inc/window.h
