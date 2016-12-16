QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = week3
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    models/computer.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    ui/mainwindow.cpp \
    ui/numberwidgetitem.cpp \
    ui/editscientist.cpp \
    ui/editcomputer.cpp \
    models/relation.cpp

HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    services/scientistservice.h \
    utilities/utils.h \
    models/computer.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    services/computerservice.h \
    services/linkservice.h \
    ui/mainwindow.h \
    ui/editscientist.h \
    ui/numberwidgetitem.h \
    ui/editcomputer.h \
    models/relation.h

DISTFILES += \
    database.sqlite

FORMS += \
    ui/mainwindow.ui \
    ui/editscientist.ui \
    ui/editcomputer.ui
