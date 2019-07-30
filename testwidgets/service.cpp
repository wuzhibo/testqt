#include "service.h"

service::service(QObject *parent) : QObject(parent)
{

}

void service::startServer()
{
    allClients = new QVector<QTcpSocket *>;

    chatServer = new QTcpServer();
    chatServer->setMaxPendingConnections(10);
    connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));

    if(chatServer->listen(QHostAddress::Any, 8001))
    {
        QDebug << "Server has started. Listening to port 8001.";
    }else
    {
        QDebug << "Server failed to start Error: " + chatServer->errorString();
    }

}

void service::newClientConnection()
{
    QTcpSocket *client = chatServer->nextPendingConnection();
    QString ipAddress  = client->peerAddress().toString();
    int port = client->peerPort();

    connect(client, &QTcpSocket::disconnected, this, &service::socketDisconnected);
    connect(client, &QTcpSocket::readyRead, this, &service::socketReadyRead);
    connect(client, &QTcpSocket::stateChanged, this, &service::socketStateChanged);
    allClients->push_back(client);
    QDebug << "Socket connected from " + ipAddress + ":" + QString::number(port);
}


void service::socketDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(QObject::sender());
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    QDebug << "Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
}


void service::socketReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(QObject::sender());
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    QString data = QString(client->readAll());
    QDebug << "Message: " + data + " (" + socketIpAddress + ":" + QString::number(port) + ")";
    sendMessageToClients(data);

}

void service::socketStateChanged(QAbstractSocket::SocketState state)
{


}
