/********************************************************************************
** Form generated from reading UI file 'filedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDIALOG_H
#define UI_FILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_FileDialog
{
public:
    QScrollBar *verticalScrollBar;
    QPushButton *pushButton;
    QPushButton *buttonLoad;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *fileSpinBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *FileDialog)
    {
        if (FileDialog->objectName().isEmpty())
            FileDialog->setObjectName("FileDialog");
        FileDialog->resize(500, 300);
        verticalScrollBar = new QScrollBar(FileDialog);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(450, 25, 25, 150));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        pushButton = new QPushButton(FileDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(25, 250, 100, 25));
        buttonLoad = new QPushButton(FileDialog);
        buttonLoad->setObjectName("buttonLoad");
        buttonLoad->setGeometry(QRect(200, 250, 100, 25));
        pushButton_3 = new QPushButton(FileDialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(375, 250, 100, 25));
        label = new QLabel(FileDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(25, 210, 100, 25));
        label_2 = new QLabel(FileDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 210, 100, 25));
        fileSpinBox = new QSpinBox(FileDialog);
        fileSpinBox->setObjectName("fileSpinBox");
        fileSpinBox->setGeometry(QRect(135, 205, 50, 40));
        lineEdit = new QLineEdit(FileDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 210, 175, 25));

        retranslateUi(FileDialog);

        QMetaObject::connectSlotsByName(FileDialog);
    } // setupUi

    void retranslateUi(QDialog *FileDialog)
    {
        FileDialog->setWindowTitle(QCoreApplication::translate("FileDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FileDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        buttonLoad->setText(QCoreApplication::translate("FileDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FileDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("FileDialog", "\320\235\320\276\320\274\320\265\321\200 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("FileDialog", "\320\224\321\200\321\203\320\263\320\276\320\271 \321\204\320\260\320\271\320\273:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileDialog: public Ui_FileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDIALOG_H
