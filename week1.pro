QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = week3
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
    utilities/computercomparator.cpp \
    services/computerservice.cpp \
    db/database.cpp \
    ui/mainwindow.cpp

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
    utilities/computercomparator.h \
    db/database.h \
    ui/mainwindow.h

DISTFILES += \
    scientists.sqlite

FORMS += \
    ui/mainwindow.ui
