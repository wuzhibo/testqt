#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include "testcharts.h"
#include "testimage.h"
#include "service.h"
#include "message.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>

#include<QtDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QMenuBar>
#include<QMenu>
#include<QMetaEnum>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void keyPressEvent(QKeyEvent * event);

private slots:
    void on_loginButton_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    testcharts *charts;
    testimage *image;
    service *server;
    message *tmessage;

};

#endif // MAINWINDOW_H
