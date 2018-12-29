# Project file

QT += core gui multimedia network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

mac {
    TARGET = Coal
}
!mac {
    TARGET = coal
}

TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

### FILES ###
SOURCES += Coal/Main.cpp
SOURCES += Coal/AppConfig.cpp
HEADERS += Coal/AppConfig.h
SOURCES += Coal/StdPaths.cpp
HEADERS += Coal/StdPaths.h
#############