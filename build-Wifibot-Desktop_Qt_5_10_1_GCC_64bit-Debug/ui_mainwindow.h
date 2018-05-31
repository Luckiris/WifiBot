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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QPushButton *Avance;
    QPushButton *Stop;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QToolButton *Left;
    QToolButton *Down;
    QToolButton *Right;
    QToolButton *Up;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Se_connecter;
    QPushButton *Se_deconnecter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *Rotationalite;
    QSlider *Vitesse;
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
        Avance = new QPushButton(centralWidget);
        Avance->setObjectName(QStringLiteral("Avance"));
        Avance->setGeometry(QRect(430, 440, 89, 25));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(430, 490, 89, 25));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(659, 319, 171, 91));
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

        gridLayout->addWidget(Up, 0, 1, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(659, 409, 171, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Se_connecter = new QPushButton(verticalLayoutWidget);
        Se_connecter->setObjectName(QStringLiteral("Se_connecter"));

        verticalLayout->addWidget(Se_connecter);

        Se_deconnecter = new QPushButton(verticalLayoutWidget);
        Se_deconnecter->setObjectName(QStringLiteral("Se_deconnecter"));

        verticalLayout->addWidget(Se_deconnecter);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(540, 320, 121, 181));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Rotationalite = new QSlider(horizontalLayoutWidget);
        Rotationalite->setObjectName(QStringLiteral("Rotationalite"));
        Rotationalite->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(Rotationalite);

        Vitesse = new QSlider(horizontalLayoutWidget);
        Vitesse->setObjectName(QStringLiteral("Vitesse"));
        Vitesse->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(Vitesse);

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
        Avance->setText(QApplication::translate("MainWindow", "Avance", nullptr));
        Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
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
        Se_connecter->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        Se_deconnecter->setText(QApplication::translate("MainWindow", "Se deconnecter", nullptr));
        menuWifiBot_Controller->setTitle(QApplication::translate("MainWindow", "WifiBot Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
