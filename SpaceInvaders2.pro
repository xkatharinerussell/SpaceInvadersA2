#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T15:04:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceInvaders2
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


SOURCES += main.cpp\
        dialog.cpp \
    universe.cpp \
    activebullets.cpp \
    bullet.cpp \
    farstarfieldbuilder.cpp \
    gameconfiguration.cpp \
    iofile.cpp \
    midstarfieldbuilder.cpp \
    nearstarfieldbuilder.cpp \
    spaceship.cpp \
    starfield.cpp \
    starfieldcreator.cpp

HEADERS  += dialog.h \
    universe.h \
    globaldimensions.h \
    activebullets.h \
    bullet.h \
    farstarfieldbuilder.h \
    gameconfiguration.h \
    iofile.h \
    midstarfieldbuilder.h \
    nearstarfieldbuilder.h \
    spaceship.h \
    gameelement.h \
    starfield.h \
    starfieldbuilder.h \
    starfieldcreator.h

FORMS    += dialog.ui

INCLUDEPATH += /Users/katharinerussell/Documents/github/SpaceInvadersA2/configuration/config.txt \

RESOURCES = \
    rsc.qrc

#copy the contents of the 'configuration' subdirectory of the project
# to the root of the install / build directory
copydata.commands = $(COPY_DIR) $$PWD/configuration/* $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
