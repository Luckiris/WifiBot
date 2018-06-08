/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QToolButton *Left;
    QToolButton *Down;
    QToolButton *Right;
    QToolButton *Up;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_ip;
    QLineEdit *entry_ip;
    QLabel *label_port;
    QLineEdit *entry_port;
    QPushButton *Se_connecter;
    QPushButton *Se_deconnecter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *Vitesse;
    QLabel *labelInformations;
    QLabel *labelBattery;
    QProgressBar *barBattery;
    QLabel *labelVitesse;
    QLabel *labelCaptorForwardLeft;
    QProgressBar *barCaptorForwardLeft;
    QLabel *labelCaptorForwardRight;
    QProgressBar *barCaptorForwardRight;
    QLabel *labelCaptorReverseLeft;
    QLabel *labelCaptorReverseRight;
    QProgressBar *barCaptorReverseLeft;
    QProgressBar *barCaptorReverseRight;
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
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(570, 470, 171, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Left = new QToolButton(gridLayoutWidget);
        Left->setObjectName(QStringLiteral("Left"));
        Left->setStyleSheet(QStringLiteral("border-image: url(:/Images/images/Left_Arrow.png);"));

        gridLayout->addWidget(Left, 1, 0, 1, 1);

        Down = new QToolButton(gridLayoutWidget);
        Down->setObjectName(QStringLiteral("Down"));
        Down->setStyleSheet(QStringLiteral("border-image: url(:/Images/images/Down_Arrow.png);"));

        gridLayout->addWidget(Down, 1, 1, 1, 1);

        Right = new QToolButton(gridLayoutWidget);
        Right->setObjectName(QStringLiteral("Right"));
        Right->setStyleSheet(QStringLiteral("border-image: url(:/Images/images/Right_Arrow.png);"));

        gridLayout->addWidget(Right, 1, 2, 1, 1);

        Up = new QToolButton(gridLayoutWidget);
        Up->setObjectName(QStringLiteral("Up"));
        Up->setStyleSheet(QStringLiteral("border-image: url(:/Images/images/Up_Arrow.png);"));
        Up->setAutoRepeatDelay(1);
        Up->setAutoRepeatInterval(1);

        gridLayout->addWidget(Up, 0, 1, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(880, 350, 171, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_ip = new QLabel(verticalLayoutWidget);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        verticalLayout->addWidget(label_ip);

        entry_ip = new QLineEdit(verticalLayoutWidget);
        entry_ip->setObjectName(QStringLiteral("entry_ip"));

        verticalLayout->addWidget(entry_ip);

        label_port = new QLabel(verticalLayoutWidget);
        label_port->setObjectName(QStringLiteral("label_port"));

        verticalLayout->addWidget(label_port);

        entry_port = new QLineEdit(verticalLayoutWidget);
        entry_port->setObjectName(QStringLiteral("entry_port"));

        verticalLayout->addWidget(entry_port);

        Se_connecter = new QPushButton(verticalLayoutWidget);
        Se_connecter->setObjectName(QStringLiteral("Se_connecter"));

        verticalLayout->addWidget(Se_connecter);

        Se_deconnecter = new QPushButton(verticalLayoutWidget);
        Se_deconnecter->setObjectName(QStringLiteral("Se_deconnecter"));
        Se_deconnecter->setEnabled(false);

        verticalLayout->addWidget(Se_deconnecter);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(770, 330, 86, 231));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Vitesse = new QSlider(horizontalLayoutWidget);
        Vitesse->setObjectName(QStringLiteral("Vitesse"));
        Vitesse->setEnabled(false);
        Vitesse->setMaximum(240);
        Vitesse->setSliderPosition(100);
        Vitesse->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(Vitesse);

        labelInformations = new QLabel(centralWidget);
        labelInformations->setObjectName(QStringLiteral("labelInformations"));
        labelInformations->setGeometry(QRect(870, 20, 101, 16));
        labelBattery = new QLabel(centralWidget);
        labelBattery->setObjectName(QStringLiteral("labelBattery"));
        labelBattery->setGeometry(QRect(760, 60, 121, 16));
        barBattery = new QProgressBar(centralWidget);
        barBattery->setObjectName(QStringLiteral("barBattery"));
        barBattery->setGeometry(QRect(940, 60, 118, 23));
        barBattery->setValue(0);
        labelVitesse = new QLabel(centralWidget);
        labelVitesse->setObjectName(QStringLiteral("labelVitesse"));
        labelVitesse->setGeometry(QRect(790, 200, 55, 229));
        labelCaptorForwardLeft = new QLabel(centralWidget);
        labelCaptorForwardLeft->setObjectName(QStringLiteral("labelCaptorForwardLeft"));
        labelCaptorForwardLeft->setGeometry(QRect(760, 100, 161, 20));
        barCaptorForwardLeft = new QProgressBar(centralWidget);
        barCaptorForwardLeft->setObjectName(QStringLiteral("barCaptorForwardLeft"));
        barCaptorForwardLeft->setGeometry(QRect(940, 100, 118, 23));
        barCaptorForwardLeft->setValue(0);
        labelCaptorForwardRight = new QLabel(centralWidget);
        labelCaptorForwardRight->setObjectName(QStringLiteral("labelCaptorForwardRight"));
        labelCaptorForwardRight->setGeometry(QRect(760, 140, 161, 20));
        barCaptorForwardRight = new QProgressBar(centralWidget);
        barCaptorForwardRight->setObjectName(QStringLiteral("barCaptorForwardRight"));
        barCaptorForwardRight->setGeometry(QRect(940, 140, 118, 23));
        barCaptorForwardRight->setValue(0);
        labelCaptorReverseLeft = new QLabel(centralWidget);
        labelCaptorReverseLeft->setObjectName(QStringLiteral("labelCaptorReverseLeft"));
        labelCaptorReverseLeft->setGeometry(QRect(760, 180, 161, 20));
        labelCaptorReverseRight = new QLabel(centralWidget);
        labelCaptorReverseRight->setObjectName(QStringLiteral("labelCaptorReverseRight"));
        labelCaptorReverseRight->setGeometry(QRect(760, 220, 161, 20));
        barCaptorReverseLeft = new QProgressBar(centralWidget);
        barCaptorReverseLeft->setObjectName(QStringLiteral("barCaptorReverseLeft"));
        barCaptorReverseLeft->setGeometry(QRect(940, 180, 118, 23));
        barCaptorReverseLeft->setValue(0);
        barCaptorReverseRight = new QProgressBar(centralWidget);
        barCaptorReverseRight->setObjectName(QStringLiteral("barCaptorReverseRight"));
        barCaptorReverseRight->setGeometry(QRect(940, 220, 118, 23));
        barCaptorReverseRight->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1261, 26));
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
        Left->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Left->setShortcut(QApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_NO_SHORTCUT
        Down->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Down->setShortcut(QApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_NO_SHORTCUT
        Right->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Right->setShortcut(QApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_NO_SHORTCUT
        Up->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Up->setShortcut(QApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_NO_SHORTCUT
        label_ip->setText(QApplication::translate("MainWindow", "IP", nullptr));
        entry_ip->setText(QApplication::translate("MainWindow", "192.168.1.106", nullptr));
        label_port->setText(QApplication::translate("MainWindow", "Port", nullptr));
        entry_port->setText(QApplication::translate("MainWindow", "15020", nullptr));
        Se_connecter->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        Se_deconnecter->setText(QApplication::translate("MainWindow", "Se deconnecter", nullptr));
        labelInformations->setText(QApplication::translate("MainWindow", "Informations", nullptr));
        labelBattery->setText(QApplication::translate("MainWindow", "Batterie : ", nullptr));
        labelVitesse->setText(QApplication::translate("MainWindow", "Vitesse", nullptr));
        labelCaptorForwardLeft->setText(QApplication::translate("MainWindow", "Capteur Avant Gauche", nullptr));
        labelCaptorForwardRight->setText(QApplication::translate("MainWindow", "Capteur Avant Droit", nullptr));
        labelCaptorReverseLeft->setText(QApplication::translate("MainWindow", "Capteur Arri\303\250re Gauche", nullptr));
        labelCaptorReverseRight->setText(QApplication::translate("MainWindow", "Capteur Arri\303\250re Droit", nullptr));
        menuWifiBot_Controller->setTitle(QApplication::translate("MainWindow", "WifiBot Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
