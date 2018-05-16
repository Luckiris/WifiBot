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

void Network::DoConnect(){
    this->socket = new QTcpSocket(this);
    this->connect(this->socket, SIGNAL(connected()),this, SLOT(connected()));
    //connect(pointeur_sur_Emetteur, &ClasseEmetteur::signalAEmettre, pointeur_sur_recepteur, &ClasseRecepteur:
    this->connect(this->socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    this->connect(this->socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    this->connect(this->socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    this->socket->connectToHost("192.168.1.106", 15020);
    if (!socket->waitForConnected(5000)){
        qDebug() << "Erreur à la connexion :" << socket->errorString();
    }
}

void Network::DoDisconnect(){
    this->socket->disconnectFromHost();
    this->socket->close();
}

void Network::connected(){
    qDebug() << "connected...";

    // Hey server, tell me about you.
    //socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void Network::disconnected(){
    qDebug() << "disconnected...";
}

void Network::bytesWritten(qint64 bytes){
    qDebug() << bytes << " bytes written...";
}


void Network::readyRead(){
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << socket->readAll();
}

void Network::SendMessage(char *msg){
    socket->write(msg);
}
