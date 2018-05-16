#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"
#include "message.h"

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
    void on_buttonConnect_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Network n;
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
};

#endif // MAINWINDOW_H
