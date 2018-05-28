/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Se_connecter;
    QPushButton *Avance;
    QPushButton *Stop;
    QPushButton *Se_deconnecter;
    QPushButton *Haut;
    QMenuBar *menuBar;
    QMenu *menuWifiBot_Controller;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1261, 633);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Se_connecter = new QPushButton(centralWidget);
        Se_connecter->setObjectName(QStringLiteral("Se_connecter"));
        Se_connecter->setGeometry(QRect(580, 440, 93, 28));
        Avance = new QPushButton(centralWidget);
        Avance->setObjectName(QStringLiteral("Avance"));
        Avance->setGeometry(QRect(430, 440, 89, 25));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(430, 490, 89, 25));
        Se_deconnecter = new QPushButton(centralWidget);
        Se_deconnecter->setObjectName(QStringLiteral("Se_deconnecter"));
        Se_deconnecter->setGeometry(QRect(580, 490, 89, 25));
        Haut = new QPushButton(centralWidget);
        Haut->setObjectName(QStringLiteral("Haut"));
        Haut->setGeometry(QRect(310, 370, 71, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1261, 22));
        menuWifiBot_Controller = new QMenu(menuBar);
        menuWifiBot_Controller->setObjectName(QStringLiteral("menuWifiBot_Controller"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuWifiBot_Controller->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Se_connecter->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        Avance->setText(QApplication::translate("MainWindow", "Avance", nullptr));
        Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        Se_deconnecter->setText(QApplication::translate("MainWindow", "Se deconnecter", nullptr));
        Haut->setText(QApplication::translate("MainWindow", "Haut", nullptr));
        menuWifiBot_Controller->setTitle(QApplication::translate("MainWindow", "WifiBot Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
