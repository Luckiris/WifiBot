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
    Message(int speedLeft, int speedRight);
    QByteArray GetData();
    void Left();
    void Right();
    void Reverse();
    void Forward();
    void BuildMessage();
};

#endif // MESSAGE_H
