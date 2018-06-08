#include "network.h"

Network::Network(QObject *parent, QString ip, int port): QObject(parent){
    this->ip = ip;
    this->port = port;
}

void Network::DoConnect(){
    this->socket = new QTcpSocket(this);
    this->connect(this->socket, SIGNAL(connected()),this, SLOT(connected()));
    this->connect(this->socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    this->connect(this->socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    this->connect(this->socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    this->socket->connectToHost(ip, port);
    if (!socket->waitForConnected(5000)){
        qDebug() << "Erreur à la connexion :" << socket->errorString();
    }
}

void Network::DoDisconnect(){
    this->socket->disconnectFromHost();
    this->socket->close();
}

void Network::connected(){
    qDebug() << "[CONNECT] Connecté au WifiBot ...";
}

void Network::disconnected(){
    qDebug() << "[DISCONNECT] Déconnecté du WifiBot ...";
}

void Network::bytesWritten(qint64 bytes){
    qDebug() << "[INFO] " << bytes << " bytes écris ...";
}

void Network::readyRead(){
    messageReceived.SetData(socket->readAll());
}

void Network::SendMessage(Message message){
    this->socket->write(message.GetData());
}

Message Network::GetMessage(){
    return messageReceived;
}
