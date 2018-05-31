#include "message.h"
#include <QString>
#include <QDebug>

Message::Message(int turnLeft, int turnRight, int speedLeft, int speedRight)
{
    this->turnLeft = turnLeft;
    this->turnRight = turnRight;
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
    speedLeft -= turnLeft;
}

void Message::Right(){
    speedRight += turnRight;
}

void Message::Forward(){
    reverseLeft = false;
    reverseRight = false;
}

void Message::Reverse(){
    reverseLeft = true;
    reverseRight = true;
}

void Message::ReadToRaw(int SpeedLeft, int SpeedRight, int sensLeft, int sensRight){
//    int char7=248;
//    Data[2]=(char) SpeedLeft;//vitesse de gauche 0 -> 240
//    Data[4]=(char) SpeedRight;//vit de droite 0 -> 240
//    if(sensLeft==-1){
//        char7=char7-64;
//    }
//    if(sensRight==-1){
//        char7=char7-16;
//    }
//    Data[6]=char7;//[255,0x07,240,0,240,0,248,0,0]
}

void Message::RawToRead(int Raw[]){
//    SpeedL=(int)((Raw[1]<<8) + Raw[0]);
//    if (SpeedL > 32767) SpeedL=SpeedL-65536;
//    BatLevel=Raw[2];
//    IR1L=Raw[3];
//    IR2L=Raw[4];
//    OdometryL=((((long)Raw[8] << 24))+(((long)Raw[7] <<
//    16))+(((long)Raw[6] << 8))+((long)Raw[5]));
//    SpeedR=(int)(Raw[10] << 8) + Raw[9];
//    if (SpeedR > 32767) SpeedR=SpeedR-65536;
//    IR1R=Raw[11];
//    IR2R=Raw[12];
//    OdometryR=((((long)Raw[16] << 24))+(((long)Raw[15] <<
//    16))+(((long)Raw[14] << 8))+((long)Raw[13]));
//    Current=Raw[17];
//    Version=Raw[18];
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

void Message::SetData(QString newData){
    this->data.append(newData);
}
