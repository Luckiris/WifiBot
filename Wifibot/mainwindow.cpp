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
    //===================UP
    if (up && down){
        Message m(0 ,0);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up && left){
        Message m(0 ,240);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up && right){
        Message m(240 ,0);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up){
        Message m(240 ,240);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //==================DOWN
    else if (down && left){
        Message m(240 ,0);
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (down && right){
        Message m(0 ,240);
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (down){
        Message m(240 ,240);
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //====================LEFT
    else if (left && right){
        Message m(0 ,0);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (left){
        Message m(240 ,240);
        m.Left();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //=======================RIGHT
    else if (right){
        Message m(240 ,240);
        m.Right();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //=====================NOTHING
    else {
        Message m(0 ,0);
        m.BuildMessage();
        network->SendMessage(m);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Z) up = true;
    if (event->key() == Qt::Key_S) down = true;
    if (event->key() == Qt::Key_Q) left = true;
    if (event->key() == Qt::Key_D) right = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Z) up = false;
    if (event->key() == Qt::Key_S) down = false;
    if (event->key() == Qt::Key_Q) left = false;
    if (event->key() == Qt::Key_D) right = false;
}
