#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T18:45:39
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = rectangletests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += rectangletests.cpp\
    ../boundingrectangle.cpp \
    ../point.cpp \
    ../shape.cpp \
    ../rectangle.cpp \
    ../square.cpp \
    ../circle.cpp \
    ../triangle.cpp \
    ../shapemanager.cpp \
    ../line.cpp \
    ../constants.cpp \
    triangletests.cpp \
    main.cpp \
    squaretests.cpp \
    circletests.cpp \
    rectanglecircletests.cpp \
    squarecircletests.cpp \
    trianglecircletests.cpp \
    trianglesquaretests.cpp \
    trianglerectangletests.cpp \
    rectanglesquaretests.cpp \
    shapemanagertests.cpp

HEADERS  += ../shape.h \
    ../shapetype.h \
    ../boundingrectangle.h \
    ../point.h \
    ../rectangle.h \
    ../square.h \
    ../circle.h \
    ../triangle.h \
    ../shapemanager.h \
    ../constants.h \
    ../line.h \
    ../orientationtype.h \
    rectangletests.h \
    triangletests.h \
    squaretests.h \
    circletests.h \
    rectanglecircletests.h \
    squarecircletests.h \
    trianglecircletests.h \
    trianglesquaretests.h \
    trianglerectangletests.h \
    rectanglesquaretests.h \
    shapemanagertests.h
DEFINES += SRCDIR=\\\"$$PWD/\\\"
