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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
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
    QSlider *Vitesse;
    QToolButton *Right;
    QToolButton *Up;
    QToolButton *Down;
    QToolButton *Left;
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
        Vitesse = new QSlider(centralWidget);
        Vitesse->setObjectName(QStringLiteral("Vitesse"));
        Vitesse->setGeometry(QRect(310, 370, 16, 160));
        Vitesse->setOrientation(Qt::Vertical);
        Right = new QToolButton(centralWidget);
        Right->setObjectName(QStringLiteral("Right"));
        Right->setGeometry(QRect(620, 270, 24, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Images/arrows/Right_Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        Right->setIcon(icon);
        Up = new QToolButton(centralWidget);
        Up->setObjectName(QStringLiteral("Up"));
        Up->setGeometry(QRect(570, 220, 26, 24));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../Images/arrows/Up_Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        Up->setIcon(icon1);
        Down = new QToolButton(centralWidget);
        Down->setObjectName(QStringLiteral("Down"));
        Down->setGeometry(QRect(570, 270, 26, 24));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../../Images/arrows/Down_Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        Down->setIcon(icon2);
        Left = new QToolButton(centralWidget);
        Left->setObjectName(QStringLiteral("Left"));
        Left->setGeometry(QRect(520, 270, 26, 24));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../../Images/arrows/Left_Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        Left->setIcon(icon3);
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
        Se_connecter->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        Avance->setText(QApplication::translate("MainWindow", "Avance", nullptr));
        Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        Se_deconnecter->setText(QApplication::translate("MainWindow", "Se deconnecter", nullptr));
        Right->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Right->setShortcut(QApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_NO_SHORTCUT
        Up->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Up->setShortcut(QApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_NO_SHORTCUT
        Down->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Down->setShortcut(QApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_NO_SHORTCUT
        Left->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        Left->setShortcut(QApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_NO_SHORTCUT
        menuWifiBot_Controller->setTitle(QApplication::translate("MainWindow", "WifiBot Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
