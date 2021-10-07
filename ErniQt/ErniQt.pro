TEMPLATE = app
TARGET = erni_qt

CONFIG += c++11

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

DISTFILES += \
    doc/basicclassdiagram.qmodel

CONFIG -= debug_and_release debug_and_release_target
CONFIG(debug, debug|release) {
    BUILDDIR = build/debug
} else {
    BUILDDIR = build/release
}

DESTDIR = $${BUILDDIR}/bin
OBJECTS_DIR = $${BUILDDIR}/obj
MOC_DIR = $${BUILDDIR}/moc
UI_DIR = $${BUILDDIR}/ui
MAKEFILE = $${BUILDDIR}/Makefile
