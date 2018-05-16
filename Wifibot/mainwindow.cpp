#include "mainwindow.h"
#include "ui_mainwindow.h"
//Commentaire useless
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    Network n;
    n.DoConnect();
}
