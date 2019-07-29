#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 添加 charts 到主界面系统
    charts = new testcharts(this);
    ui->stackedWidget->addWidget(charts);

    // 添加 image 到主界面系统
    image = new testimage(this);
    ui->stackedWidget->addWidget(image);


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

            // 更多有关 list tree table 的例子  https://doc.qt.io/qt-5/examples-itemviews.html
            // 添加 listwidget 的子选项
            ui->listWidget->addItem("My Test Item");
            QListWidgetItem *listitem = new QListWidgetItem;
            listitem->setText("My Second Item");
            listitem->setData(100, 1000);
            qDebug() << listitem->data(100);
            ui->listWidget->addItem(listitem);

            // 添加 treewidget 的子选项
            QTreeWidgetItem *treeItem = new QTreeWidgetItem;
            treeItem->setText(0, "My Test Item");
            ui->treeWidget->addTopLevelItem(treeItem);

            QTreeWidgetItem *treeItme2 = new QTreeWidgetItem;
            treeItme2->setText(0, "My Test Subitem");
            treeItem->addChild(treeItme2);

            // 添加tablewidget的子选项
            QTableWidgetItem *tableItem = new QTableWidgetItem;
            tableItem->setText("Testing1");
            ui->tableWidget->setItem(0, 0, tableItem);

            QTableWidgetItem *tableItem2 = new QTableWidgetItem;
            tableItem2->setText("Testing2");
            ui->tableWidget->setItem(1, 2, tableItem2);

            // 更多有关 QMessageBox 的例子 http://doc.qt.io/qt-5/qdialog.html
            QMessageBox::information(this, "欢迎您来", "您以来到操作界面请进入观看");
            QMessageBox::question(this, "您的登录有问题!", "看看您的用户名和密码是不是不正确!", QMessageBox::Ignore, QMessageBox::Yes);
            QMessageBox::warning(this, "设置异常!", "设置异常");
            QMessageBox::critical(this, "严重问题!", "要爆炸了房价");

            if(QMessageBox::question(this, "你选择我还是她", "你选择我还是她") == QMessageBox::Yes)
            {
                QMessageBox::warning(this, "Yes", "You have pressed Yes!");
            }else
            {
                QMessageBox::warning(this, "No", "You have pressed No!");
            }


            // 设置当前显示为dashboard
            //ui->stackedWidget->setCurrentWidget(ui->dashboard);
            ui->stackedWidget->setCurrentWidget(image);
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


