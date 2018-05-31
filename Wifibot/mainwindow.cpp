#include "mainwindow.h"
#include "ui_mainwindow.h"
//Commentaire useless
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    network = new Network(this, "192.168.1.106", 15020);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete network;
    delete ui;
}

void MainWindow::on_Se_connecter_clicked()
{
    network->DoConnect();
    timer->start(25);
}

void MainWindow::on_Se_deconnecter_clicked(){
    timer->stop();
    network->DoDisconnect();
}

short MainWindow::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max){
    unsigned int Crc = 0xFFFF;
    unsigned int Polynome = 0xA001;
    unsigned int CptOctet = 0;
    unsigned int CptBit = 0;
    unsigned int Parity= 0;
    Crc = 0xFFFF;
    Polynome = 0xA001;
    for ( CptOctet= 0 ; CptOctet < Taille_max ; CptOctet++){
        Crc ^= *( Adresse_tab + CptOctet);
        for ( CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true) Crc ^= Polynome;
        }
    }
    return(Crc);
}

void MainWindow::on_Vitesse_valueChanged(int value){

}

void MainWindow::updateTimer(){
    if (up){
        Message m(240 ,240);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (down){
        Message m(240 ,240);
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (left){
        Message m(240 ,240);
        m.Left();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (right){
        Message m(240 ,240);
        m.Right();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else {
        Message m(0 ,0);
        m.BuildMessage();
        network->SendMessage(m);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Z) up = true;
    else if (event->key() == Qt::Key_S) down = true;
    else if (event->key() == Qt::Key_Q) left = true;
    else if (event->key() == Qt::Key_D) right = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Z) up = false;
    else if (event->key() == Qt::Key_S) down = false;
    else if (event->key() == Qt::Key_Q) left = false;
    else if (event->key() == Qt::Key_D) right = false;
}
