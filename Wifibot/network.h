#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QList>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class Network : public QObject
{
private:
    //QList<Message> listMessagesToSend;
    //QList<Message> listMessagesReceived;
    QString ip;
    int port;
    QTcpSocket *socket;
public:
    Network(QObject *parent = 0, QString ip = "0.0.0.0", int port = 0);
    //void AddMessage(Message m);
    void ClearList();
    void DoConnect();
    void DoDisconnect();

public slots:
    void connected();
    void readyRead();
    void bytesWritten(qint64 bytes);
    void disconnected();
};

#endif // NETWORK_H
