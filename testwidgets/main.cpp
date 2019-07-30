#include "mainwindow.h"
#include <QApplication>

// 所有源码地址： https://github.com/PacktPublishing/Hands-On-GUI-Programming-with-CPP-and-Qt5

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
