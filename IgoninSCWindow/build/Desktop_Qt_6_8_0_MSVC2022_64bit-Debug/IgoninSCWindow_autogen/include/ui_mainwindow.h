/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ButtonMenuFile;
    QAction *ButtonMenuSave;
    QAction *ButtonMenuClear;
    QAction *ButtonManager;
    QWidget *centralwidget;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 598);
        ButtonMenuFile = new QAction(MainWindow);
        ButtonMenuFile->setObjectName("ButtonMenuFile");
        ButtonMenuSave = new QAction(MainWindow);
        ButtonMenuSave->setObjectName("ButtonMenuSave");
        ButtonMenuClear = new QAction(MainWindow);
        ButtonMenuClear->setObjectName("ButtonMenuClear");
        ButtonManager = new QAction(MainWindow);
        ButtonManager->setObjectName("ButtonManager");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setGeometry(QRect(160, 520, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Orientation::Horizontal);
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(360, 380, 16, 160));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 430, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(ButtonMenuFile);
        menu->addAction(ButtonMenuSave);
        menu->addAction(ButtonMenuClear);
        menu->addAction(ButtonManager);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonMenuFile->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        ButtonMenuSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        ButtonMenuClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        ButtonManager->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
