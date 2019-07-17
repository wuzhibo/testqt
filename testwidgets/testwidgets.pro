#-------------------------------------------------
#
# Project created by QtCreator 2019-07-16T10:25:31
#
#-------------------------------------------------

QT       += core gui sql



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += $$quote(C:\Program Files\MySQL\MySQL Connector C 6.1\include)
LIBS+= -L$$quote(C:\Program Files\MySQL\MySQL Connector C 6.1\lib) -llibmysql
TARGET = testwidgets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
