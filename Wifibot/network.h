#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QList>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <message.h>

class Network : public QObject
{
    Q_OBJECT
private:
    QString ip;
    int port;
    QTcpSocket *socket;
    Message messageReceived;
public:
    Network(QObject *parent, QString ip, int port);
    void DoConnect();
    void DoDisconnect();
    void SendMessage(Message message);
    Message GetMessage();

public slots:
    void connected();
    void readyRead();
    void bytesWritten(qint64 bytes);
    void disconnected();
};

#endif // NETWORK_H
