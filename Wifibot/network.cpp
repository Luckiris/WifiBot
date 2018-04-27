#include "network.h"

Network::Network(QObject *parent, QString ip, int port): QObject(parent){
    //this->listMessagesToReceive = new QList<Message>();
    //this->listMessagesToSend = new QList<Message>();
    this->ip = ip;
    this->port = port;
}

/*void Network::AddMessage(Message m){
    listMessagesToSend.append(m);
}

void Network::ClearList(){
    listMessagesToSend.clear();
}*/

void Network::Connect(){
    this->socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    this->socket->connectToHost(ip, port);
    if (!socket->waitForConnected(5000)){
        qDebug() << "Erreur à la connexion :" << socket->errorString();
    }
}

void Network::Disconnect(){
    this->socket->disconnectFromHost();
    this->socket->close();
}

void Network::readyRead(){
    qDebug() << "Data lues :" << socket->readAll();
}
