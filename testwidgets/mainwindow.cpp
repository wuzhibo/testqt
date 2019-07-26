#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    charts = new testcharts(this);
//    ui->->addWidget(charts);
    db = QSqlDatabase::addDatabase("QMYSQL");
#ifdef WIN32
    db.setHostName("192.168.207.134");
#else
    db.setHostName("127.0.0.1");
#endif
    db.setPort(3306);
    db.setDatabaseName("testwidget");
    db.setUserName("root");
    db.setPassword("wuzhibo");

    if(db.open())
    {
        qDebug() << "Connected!";
    }else
    {
        qDebug() << "Failed to connect";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userinput->text();
    QString password = ui->passwordinput->text();
    qDebug()<< username << password;
    QString command = "select * from users where username = '" + username + "' AND password= '" + password + "' AND status = 0";

    QSqlQuery query(db);
    if(query.exec(command))
    {
        if(query.size() > 0)
        {
            // add next page to stackedWidget
            ui->stackedWidget->setCurrentWidget(ui->dashboard);
            //QMessageBox::information(this, "Login success.", "You have successfully logged in!");
        }
        else
        {
            QMessageBox::information(this, "Login failed.", "Login failed Please try again...");
        }
    }else
    {
        qDebug() << query.lastError();
    }



}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 1)
    {
        qDebug() << "arg1 === 1";
    }
}
