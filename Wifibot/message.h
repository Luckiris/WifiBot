#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QChar>


class Message
{
private:
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
    short GetChar7();
    QByteArray data;
    int turnLeft;
    int turnRight;
    int speedRight;
    int speedLeft;
    bool reverseRight;
    bool reverseLeft;

public:
//    char* Data[];//data a envoyer au robot depuis network
//    //QChar Raw[];//data reçus du robot depuis network
//    int SpeedL;
//    int SpeedR;
//    QChar BatLevel;
//    QChar IR1L;
//    QChar IR2L;
//    int OdometryL;
//    QChar IR1R;
//    QChar IR2R;
//    int OdometryR;
//    QChar Current;
//    QChar Version;
    Message(int turnLeft, int turnRight, int speedLeft, int speedRight);
    QByteArray GetData();
    void SetData(QString newData);
    void Left();
    void Right();
    void Reverse();
    void Forward();
    void ReadToRaw(int SpeedLeft, int SpeedRight, int sensLeft, int sensRight);
    void RawToRead(int Raw[]);
    void BuildMessage();
};

#endif // MESSAGE_H
