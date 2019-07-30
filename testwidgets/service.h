#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>

class service : public QObject
{
    Q_OBJECT
public:
    explicit service(QObject *parent = nullptr);
    void startServer();
    void sendMessageToClients(QString message);

signals:

public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadyRead();
    void socketStateChanged(QAbstractSocket::SocketState state);

private:
    QTcpServer *chatServer;
    QVector<QTcpSocket *> *allClients;
};

#endif // SERVICE_H
