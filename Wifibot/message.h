#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QChar>


class Message
{
public:
    char* Data[];//data a envoyer au robot depuis network
    //QChar Raw[];//data reçus du robot depuis network
    int SpeedL;
    int SpeedR;
    QChar BatLevel;
    QChar IR1L;
    QChar IR2L;
    int OdometryL;
    QChar IR1R;
    QChar IR2R;
    int OdometryR;
    QChar Current;
    QChar Version;
    Message();
    QByteArray data;
    void ReadToRaw(int SpeedLeft, int SpeedRight, int sensLeft, int sensRight);
    void RawToRead(int Raw[]);
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
    QByteArray GetData();
};

#endif // MESSAGE_H
