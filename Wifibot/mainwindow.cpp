#include "mainwindow.h"
#include "ui_mainwindow.h"
//Commentaire useless
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    n.DoConnect();
}

void MainWindow::on_pushButton_clicked()//bouton avance
{
    char* msg[7];
    char* msg_[9];
    msg_[0]="255";
    msg[0]="0x07";
    msg[1]="0";//3
    msg[2]="120";
    msg[3]="0";
    msg[4]="120";
    msg[5]="0x50";
    //short temp=Crc16(msg,6);
    msg_;
    for(int i=0;i<6;i++){
        msg_[i+1]=msg[i];
    }
    //msg_[7]=temp;
    //msg_[8]=(temp>>8);
    qDebug()<<msg;
    //qDebug()<<temp;
    qDebug()<<msg_;
    //n.SendMessage(msg_);
}

void MainWindow::on_pushButton_2_clicked()//bouton stop
{
    char* msg[7];
    char* msg_[9];
    msg_[0]="255";
    msg[0]="0x07";
    msg[1]="0";//3
    msg[2]="0";
    msg[3]="0";
    msg[4]="0";
    msg[5]="0x50";
    //short temp=Crc16(&msg,6);
    msg_;
    for(int i=0;i<6;i++){
        msg_[i+1]=msg[i];
    }
    //msg_[7]=temp;
    //msg_[8]=(temp>>8);
    qDebug()<<msg;
    //qDebug()<<temp;
    qDebug()<<msg_;
    //n.SendMessage(msg_);
}

void MainWindow::on_pushButton_3_clicked()//bouton deco
{
    n.DoDisconnect();
}

short MainWindow::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max)
{
    unsigned int Crc = 0xFFFF;
    unsigned int Polynome = 0xA001;
    unsigned int CptOctet = 0;
    unsigned int CptBit = 0;
    unsigned int Parity= 0;
    Crc = 0xFFFF;
    Polynome = 0xA001;
    for ( CptOctet= 0 ; CptOctet < Taille_max ; CptOctet++)
    {
        Crc ^= *( Adresse_tab + CptOctet);
        for ( CptBit = 0; CptBit <= 7 ; CptBit++)
        {
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true) Crc ^= Polynome;
        }
    }
    return(Crc);
}
