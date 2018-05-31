#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"
#include "message.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    ~MainWindow();

private slots:
    void on_Se_connecter_clicked();

    void on_Se_deconnecter_clicked();

    void on_Vitesse_valueChanged(int value);

    void updateTimer();

private:
    Ui::MainWindow *ui;
    Network *network;
    QTimer *timer;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
};

#endif // MAINWINDOW_H
