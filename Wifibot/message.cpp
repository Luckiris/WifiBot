#include "message.h"
#include <QString>
#include <QDebug>

Message::Message(int speedLeft, int speedRight)
{
    this->speedLeft = speedLeft;
    this->speedRight = speedRight;
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
    short resultat;
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

short Message::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max)
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

QByteArray Message::GetData(){
    return data;
}
