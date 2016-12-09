QT += core
QT -= gui
QT += sql

TARGET = week1
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    utilities/utils.cpp \
    utilities/scientistcomparator.cpp \
    models/computer.cpp \
    repositories/computerrepository.cpp \
    utilities/computercomparator.cpp

HEADERS += \
    models/scientist.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    ui/consoleui.h \
    utilities/scientistcomparator.h \
    utilities/enums.h \
    repositories/computerrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    models/computer.h \
    utilities/computercomparator.h

DISTFILES += \
    scientists.sqlite

