#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerSend = new QTimer(this);
    timerReceive = new QTimer(this);
    connect(timerSend, SIGNAL(timeout()), this, SLOT(updateTimerSend()));
    connect(timerReceive, SIGNAL(timeout()), this, SLOT(updateTimerReceive()));
}

MainWindow::~MainWindow(){
    delete timerSend;
    delete timerReceive;
    delete ui;
}

void MainWindow::on_Se_connecter_clicked(){
    this->ui->Vitesse->setEnabled(true);
    this->ui->entry_ip->setEnabled(false);
    this->ui->entry_port->setEnabled(false);
    this->ui->Se_connecter->setEnabled(false);
    this->ui->Se_deconnecter->setEnabled(true);
    network = new Network(this, ui->entry_ip->text(), ui->entry_port->text().toInt());
    network->DoConnect();
    timerSend->start(25);
    timerReceive->start(500);
}

void MainWindow::on_Se_deconnecter_clicked(){
    this->ui->Vitesse->setEnabled(false);
    this->ui->entry_ip->setEnabled(true);
    this->ui->entry_port->setEnabled(true);
    this->ui->Se_connecter->setEnabled(true);
    this->ui->Se_deconnecter->setEnabled(false);
    ResetUI();
    timerSend->stop();
    timerReceive->stop();
    network->DoDisconnect();
    delete network;
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

void MainWindow::on_Vitesse_valueChanged(){
    Message m(ui->Vitesse->value() , ui->Vitesse->value());
    m.BuildMessage();
    network->SendMessage(m);
}

void MainWindow::updateTimerSend(){
    //===================UP
    if (up && down){
        Message m;
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up && left){
        Message m(0 , ui->Vitesse->value());
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up && right){
        Message m(ui->Vitesse->value(), 0);
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (up){
        Message m(ui->Vitesse->value(), ui->Vitesse->value());
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //==================DOWN
    else if (down && left){
        Message m(ui->Vitesse->value(), 0);
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (down && right){
        Message m(0 ,ui->Vitesse->value());
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (down){
        Message m(ui->Vitesse->value(), ui->Vitesse->value());
        m.Reverse();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //====================LEFT
    else if (left && right){
        Message m;
        m.Forward();
        m.BuildMessage();
        network->SendMessage(m);
    }
    else if (left){
        Message m(ui->Vitesse->value() , ui->Vitesse->value());
        m.Left();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //=======================RIGHT
    else if (right){
        Message m(ui->Vitesse->value() , ui->Vitesse->value());
        m.Right();
        m.BuildMessage();
        network->SendMessage(m);
    }
    //=====================NOTHING
    else {
        Message m;
        m.BuildMessage();
        network->SendMessage(m);
    }
}

void MainWindow::updateTimerReceive(){
    Message message = network->GetMessage();
    message.ShowMessage();
    message.UnbuildMessage();
    UpdateUI(message);
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

void MainWindow::UpdateUI(Message message){
    UpdateBattery(message.GetBattery());
    UpdateCaptor(message.GetCaptorForwardLeft(), message.GetCaptorForwardRight(), message.GetCaptorReverseLeft(), message.GetCaptorReverseRight());
}

void MainWindow::UpdateBattery(int batteryLevel){
    if (batteryLevel < 0){
        batteryLevel = 100;
        this->ui->barBattery->setFormat(" En charge");
    }
    else {
        batteryLevel = (batteryLevel-100)*3.57;
        this->ui->barBattery->setFormat("%p%");
    }
    this->ui->barBattery->setValue(batteryLevel);
}

void MainWindow::UpdateCaptor(int forwardLeft, int forwardRight, int reverseLeft, int reverseRight){
    qDebug() << "IR AVANT GAUCHE : " << forwardLeft;
    qDebug() << "IR AVANT DROIT : " << forwardRight;
    qDebug() << "IR ARRIRE GAUCHE : " << reverseLeft;
    qDebug() << "IR ARRIRE DROIT : " << reverseRight;

    if (forwardLeft < 0) this->ui->barCaptorForwardLeft->setValue((forwardLeft + 255)/2.5);
    else this->ui->barCaptorForwardLeft->setValue(forwardLeft);

    if (forwardRight < 0) this->ui->barCaptorForwardLeft->setValue((forwardRight + 255)/2.5);
    else this->ui->barCaptorForwardLeft->setValue(forwardRight);

    if (reverseLeft < 0) this->ui->barCaptorForwardLeft->setValue((reverseLeft + 255)/2.5);
    else this->ui->barCaptorForwardLeft->setValue(reverseLeft);

    if (reverseRight < 0) this->ui->barCaptorForwardLeft->setValue((reverseRight + 255)/2.5);
    else this->ui->barCaptorForwardLeft->setValue(reverseRight);
}

void MainWindow::ResetUI(){
    this->ui->barBattery->setValue(0);
    this->ui->barCaptorForwardLeft->setValue(0);
    this->ui->barCaptorForwardRight->setValue(0);
    this->ui->barCaptorReverseLeft->setValue(0);
    this->ui->barCaptorReverseRight->setValue(0);
}
