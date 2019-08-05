#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QMessageBox>


namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = 0);
    ~message();
    void printMessage(QString message);

private slots:
    void on_connect_clicked();
    void socketDisconnected();
    void socketConnected();
    void socketReadyRead();

    void on_send_clicked();

private:
    Ui::message *ui;

    QTcpSocket *socket;
    bool connectSocket;
};

#endif // MESSAGE_H
