#include "message.h"
#include <QString>
#include <QDebug>

Message::Message(int speedLeft, int speedRight){
    this->speedLeft = speedLeft;
    this->speedRight = speedRight;
    batteryLevel = 0;
    ir_right = 0;
    ir_left = 0;
    ir2_right = 0;
    ir2_left = 0;
    odometrie_right = 0.0;
    odometrie_left = 0.0;
}

void Message::BuildMessage(){
    data.append(255);
    data.append(0x07);
    data.append(speedLeft);
    data.append((char)0);
    data.append(speedRight);
    data.append((char)0);
    data.append(GetChar7());
    QByteArray data2;
    data2.append(0x07);
    data2.append(speedLeft);
    data2.append((char)0);
    data2.append(speedRight);
    data2.append((char)0);
    data2.append(GetChar7());
    short calcul = Crc16((unsigned char*)data2.constData(), data2.length());
    data.append(calcul);
    data.append(calcul>>8);
}

short Message::GetChar7(){
    short resultat = 0;
    resultat += 128;
    if (reverseLeft) resultat += 64;
    resultat += 32;
    if (reverseRight) resultat += 16;
    resultat += 8;
    return resultat;
}

void Message::Left(){
    reverseLeft = false;
    reverseRight = true;
}

void Message::Right(){
    reverseRight = false;
    reverseLeft = true;
}

void Message::Forward(){
    reverseLeft = true;
    reverseRight = true;
}

void Message::Reverse(){
    reverseLeft = false;
    reverseRight = false;
}

short Message::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max){
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

QByteArray Message::GetData(){
    return data;
}

void Message::UnbuildMessage(){
    /* Left side */
    speedLeft = (int) ((data[1] << 8) + (data[0]));
    if (speedLeft > 32767) speedLeft -= 65536;
    batteryLevel = data[2];
    ir_left = data[3];
    ir2_left = data[4];
    odometrie_left = ((((long)data[8] << 24))+(((long)data[7] << 16))+(((long)data[6] << 8))+((long)data[5]));

    /* Right side */
    speedRight = (int)(data[10] << 8) + data[9];
    if (speedRight > 32767) speedRight -= 65536;
    ir_right = data[11];
    ir2_right = data[12];
    odometrie_right = ((((long)data[16] << 24))+(((long)data[15] << 16))+(((long)data[14] << 8))+((long)data[13]));
}

void Message::SetData(QByteArray data){
    this->data = data;
}

void Message::ShowMessage(){
    qDebug() << "Message reçu : " << data;
}

int Message::GetBattery(){
    return batteryLevel;
}

int Message::GetCaptorForwardLeft(){
    return ir_left;
}

int Message::GetCaptorForwardRight(){
    return ir_right;
}

int Message::GetCaptorReverseLeft(){
    return ir2_left;
}

int Message::GetCaptorReverseRight(){
    return ir2_right;
}
