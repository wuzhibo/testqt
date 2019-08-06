#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    connectSocket = false;
}

message::~message()
{
    delete ui;
}

void message::on_connect_clicked()
{
    qDebug() << "send to message to connected";

    if(!connectSocket)
    {
        socket = new QTcpSocket();
        if(socket)
        {
            connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
            connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
            connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
            socket->connectToHost("127.0.0.1", 8001);
        }else
        {
            qDebug() << "init socket error!";
        }

    }
    else
    {
        QString name = ui->host->text();

        socket->write("<font color='Orange'>" + name.toUtf8() + " hasleft the chat room.</font>");
        socket->disconnectFromHost();

    }


}

void message::socketDisconnected()
{
    qDebug() << "Disconnected from server.";
    printMessage("<font color='Red'>Disconnected from server.</font>");
    ui->connect->setText("connect");
    connectSocket = false;
}

void message::socketConnected()
{
    qDebug() << "Connected to server.";
    printMessage("<font color='Green'>Connected to server.</font>");
    QString name = ui->host->text();
    socket->write("<font color='Purple'>" + name.toUtf8() + " has joined the chat room.</font>");
    ui->connect->setText("Disconnect");
    connectSocket = true;


}

void message::socketReadyRead()
{

    ui->textBrowser->append(socket->readAll());

}

void message::printMessage(QString message)
{
    ui->textBrowser->append(message);
}


void message::on_send_clicked()
{
    QString name = ui->host->text();
    QString message = ui->chat->text();
    if(message.size() != 0)
        socket->write("<font color='Blue'>" + name.toUtf8() + "</font>: " + message.toUtf8());
    else
         QMessageBox::information(this, "不能发送空内容", "不能发送空内容");
    ui->chat->clear();
}
