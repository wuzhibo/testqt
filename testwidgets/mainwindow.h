#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<Qtsql/QSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

#include<QtDebug>
#include<QMessageBox>
#include<QSqlError>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
