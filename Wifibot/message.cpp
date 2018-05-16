#include "message.h"
#include <QString>
#include <QChar>

Message::Message()
{
    static QChar Data[9] = { 255, 0x07,0, 0, 0, 0, 0, 0x00, 0x00 };//chaine de donné brute
    //static QChar Raw[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    static int SpeedL=0;
    static int SpeedR=0;
    static QChar BatLevel=0;
    static QChar IR1L=0;
    static QChar IR2L=0;
    static int OdometryL=0;
    static QChar IR1R=0;
    static QChar IR2R=0;
    static int OdometryR=0;
    static QChar Current=0;
    static QChar Version=0;
}

void Message::ReadToRaw(int SpeedLeft, int SpeedRight, int sensLeft, int sensRight){
    int char7=248;
    Data[2]=SpeedLeft;//vitesse de gauche 0 -> 240
    Data[4]=SpeedRight;//vit de droite 0 -> 240
    if(sensLeft==-1){
        char7=char7-64;
    }
    if(sensRight==-1){
        char7=char7-16;
    }
    Data[7]=char7;
}

void Message::RawToRead(int Raw[]){
    SpeedL=(int)((Raw[1]<<8) + Raw[0]);
    if (SpeedL > 32767) SpeedL=SpeedL-65536;
    BatLevel=Raw[2];
    IR1L=Raw[3];
    IR2L=Raw[4];
    OdometryL=((((long)Raw[8] << 24))+(((long)Raw[7] <<
    16))+(((long)Raw[6] << 8))+((long)Raw[5]));
    SpeedR=(int)(Raw[10] << 8) + Raw[9];
    if (SpeedR > 32767) SpeedR=SpeedR-65536;
    IR1R=Raw[11];
    IR2R=Raw[12];
    OdometryR=((((long)Raw[16] << 24))+(((long)Raw[15] <<
    16))+(((long)Raw[14] << 8))+((long)Raw[13]));
    Current=Raw[17];
    Version=Raw[18];
}
