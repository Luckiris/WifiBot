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
    ~MainWindow();

private slots:
    void on_Se_connecter_clicked();

    void on_Avance_clicked();

    void on_Stop_clicked();

    void on_Se_deconnecter_clicked();

    void on_Vitesse_valueChanged(int value);

    void on_Right_triggered(QAction *arg1);
    
    void on_Down_triggered(QAction *arg1);
    
    void on_Up_triggered(QAction *arg1);
    
    void on_Left_triggered(QAction *arg1);
    
    void on_Up_pressed();

    void updateTimer();

private:
    Ui::MainWindow *ui;
    Network *network;
    QTimer *timer;
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
};

#endif // MAINWINDOW_H
