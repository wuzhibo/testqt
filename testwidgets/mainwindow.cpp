#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charts = new testcharts(this);
    ui->stackedWidget->addWidget(charts);
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

    /** 添加登录按钮为回车键 **/
    ui->loginButton->setFocus();
    ui->loginButton->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->loginButton->setShortcut(Qt::Key_Enter);
    ui->loginButton->setShortcut(Qt::Key_Return);

    //connect(ui->loginButton, SIGNAL(Qt::Key_Enter), SLOT(on_loginButton_clicked()));
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
            ui->listWidget->addItem("My Test Item");
            QListWidgetItem *listitem = new QListWidgetItem;
            listitem->setText("My Second Item");
            listitem->setData(100, 1000);
            qDebug() << listitem->data(100);
            ui->listWidget->addItem(listitem);
            ui->stackedWidget->setCurrentWidget(ui->dashboard);
            //ui->stackedWidget->setCurrentWidget(charts);
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


