QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = week3
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/computer.cpp \
    models/relation.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    services/scientistservice.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    ui/numberwidgetitem.cpp \
    ui/editscientist.cpp \
    ui/editcomputer.cpp \
    ui/editrelation.cpp \
    ui/mainwindow.cpp \
    utilities/utils.cpp

HEADERS += \
    models/computer.h \
    models/relation.h \
    models/scientist.h \
    repositories/scientistrepository.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    services/scientistservice.h \
    services/computerservice.h \
    services/linkservice.h \
    ui/mainwindow.h \
    ui/editscientist.h \
    ui/numberwidgetitem.h \
    ui/editcomputer.h \
    ui/editrelation.h \
    utilities/utils.h

DISTFILES += \
    database.sqlite

FORMS += \
    ui/mainwindow.ui \
    ui/editscientist.ui \
    ui/editcomputer.ui \
    ui/editrelation.ui
