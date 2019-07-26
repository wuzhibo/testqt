#-------------------------------------------------
#
# Project created by QtCreator 2019-07-16T10:25:31
#
#-------------------------------------------------

QT       += core gui sql charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32 {
    INCLUDEPATH += $$quote(C:\Program Files\MySQL\MySQL Connector C 6.1\include)
    LIBS+= -L$$quote(C:\Program Files\MySQL\MySQL Connector C 6.1\lib) -llibmysql
}

TARGET = testwidgets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testcharts.cpp

HEADERS  += mainwindow.h \
    testcharts.h

FORMS    += mainwindow.ui \
    testcharts.ui

RESOURCES += \
    images.qrc
