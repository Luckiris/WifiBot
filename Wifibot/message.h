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
    /* Speed (also used to save) */
    int speedLeft;
    int speedRight;
    /* True = Forward && False = reverse */
    bool reverseRight;
    bool reverseLeft;
    /* Data saved for received message */
    int batteryLevel;
    int ir_right;
    int ir_left;
    int ir2_right;
    int ir2_left;
    long odometrie_right;
    long odometrie_left;

public:
    Message(int speedLeft = 0, int speedRight = 0);
    QByteArray GetData();
    void SetData(QByteArray data);
    void Left();
    void Right();
    void Reverse();
    void Forward();
    void BuildMessage();
    void UnbuildMessage();
    void ShowMessage();
    int GetSpeed();
    int GetBattery();
    int GetCaptorForwardLeft();
    int GetCaptorForwardRight();
    int GetCaptorReverseLeft();
    int GetCaptorReverseRight();
};

#endif // MESSAGE_H
