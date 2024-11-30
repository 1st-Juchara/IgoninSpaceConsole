/********************************************************************************
** Form generated from reading UI file 'igonindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IGONINDIALOG_H
#define UI_IGONINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_IgoninDialog
{
public:
    QListWidget *listWidgetAnimal;
    QTextEdit *textEditName;
    QTextEdit *textEditAge;
    QTextEdit *textEditWeight;
    QTextEdit *textEditTail;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *buttonAddAnimal;
    QPushButton *buttonChangeAnimal;
    QPushButton *buttonDeleteAnimal;
    QPushButton *buttonCloseDialog;
    QComboBox *listBoxColor;
    QComboBox *listBoxNutrition;
    QCheckBox *checkBoxPoisonous;
    QPushButton *buttonComplete;

    void setupUi(QDialog *IgoninDialog)
    {
        if (IgoninDialog->objectName().isEmpty())
            IgoninDialog->setObjectName("IgoninDialog");
        IgoninDialog->resize(640, 480);
        IgoninDialog->setMinimumSize(QSize(640, 480));
        listWidgetAnimal = new QListWidget(IgoninDialog);
        listWidgetAnimal->setObjectName("listWidgetAnimal");
        listWidgetAnimal->setGeometry(QRect(10, 10, 271, 431));
        textEditName = new QTextEdit(IgoninDialog);
        textEditName->setObjectName("textEditName");
        textEditName->setGeometry(QRect(470, 10, 150, 30));
        textEditAge = new QTextEdit(IgoninDialog);
        textEditAge->setObjectName("textEditAge");
        textEditAge->setGeometry(QRect(470, 160, 150, 30));
        textEditWeight = new QTextEdit(IgoninDialog);
        textEditWeight->setObjectName("textEditWeight");
        textEditWeight->setGeometry(QRect(470, 210, 150, 30));
        textEditTail = new QTextEdit(IgoninDialog);
        textEditTail->setObjectName("textEditTail");
        textEditTail->setGeometry(QRect(470, 310, 150, 30));
        label = new QLabel(IgoninDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 10, 120, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Impact")});
        label->setFont(font);
        label_2 = new QLabel(IgoninDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 60, 120, 30));
        label_2->setFont(font);
        label_3 = new QLabel(IgoninDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 110, 120, 30));
        label_3->setFont(font);
        label_4 = new QLabel(IgoninDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 160, 120, 30));
        label_4->setFont(font);
        label_5 = new QLabel(IgoninDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(350, 210, 120, 30));
        label_5->setFont(font);
        label_6 = new QLabel(IgoninDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(350, 260, 120, 30));
        label_6->setFont(font);
        label_7 = new QLabel(IgoninDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(350, 310, 120, 30));
        label_7->setFont(font);
        buttonAddAnimal = new QPushButton(IgoninDialog);
        buttonAddAnimal->setObjectName("buttonAddAnimal");
        buttonAddAnimal->setGeometry(QRect(310, 390, 80, 30));
        buttonChangeAnimal = new QPushButton(IgoninDialog);
        buttonChangeAnimal->setObjectName("buttonChangeAnimal");
        buttonChangeAnimal->setGeometry(QRect(420, 390, 80, 30));
        buttonDeleteAnimal = new QPushButton(IgoninDialog);
        buttonDeleteAnimal->setObjectName("buttonDeleteAnimal");
        buttonDeleteAnimal->setGeometry(QRect(530, 390, 80, 30));
        buttonCloseDialog = new QPushButton(IgoninDialog);
        buttonCloseDialog->setObjectName("buttonCloseDialog");
        buttonCloseDialog->setGeometry(QRect(530, 440, 80, 30));
        listBoxColor = new QComboBox(IgoninDialog);
        listBoxColor->setObjectName("listBoxColor");
        listBoxColor->setGeometry(QRect(470, 60, 150, 30));
        listBoxNutrition = new QComboBox(IgoninDialog);
        listBoxNutrition->setObjectName("listBoxNutrition");
        listBoxNutrition->setGeometry(QRect(470, 110, 150, 30));
        checkBoxPoisonous = new QCheckBox(IgoninDialog);
        checkBoxPoisonous->setObjectName("checkBoxPoisonous");
        checkBoxPoisonous->setGeometry(QRect(470, 260, 131, 30));
        buttonComplete = new QPushButton(IgoninDialog);
        buttonComplete->setObjectName("buttonComplete");
        buttonComplete->setGeometry(QRect(530, 350, 80, 30));

        retranslateUi(IgoninDialog);

        QMetaObject::connectSlotsByName(IgoninDialog);
    } // setupUi

    void retranslateUi(QDialog *IgoninDialog)
    {
        IgoninDialog->setWindowTitle(QCoreApplication::translate("IgoninDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("IgoninDialog", "\320\230\320\274\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("IgoninDialog", "\320\246\320\262\320\265\321\202:", nullptr));
        label_3->setText(QCoreApplication::translate("IgoninDialog", "\320\242\320\270\320\277 \320\277\320\270\321\202\320\260\320\275\320\270\321\217:", nullptr));
        label_4->setText(QCoreApplication::translate("IgoninDialog", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202:", nullptr));
        label_5->setText(QCoreApplication::translate("IgoninDialog", "\320\222\320\265\321\201:", nullptr));
        label_6->setText(QCoreApplication::translate("IgoninDialog", "\320\257\320\264\320\276\320\262\320\270\321\202\320\276\321\201\321\202\321\214:", nullptr));
        label_7->setText(QCoreApplication::translate("IgoninDialog", "\320\224\320\273\320\270\320\275\320\260 \321\205\320\262\320\276\321\201\321\202\320\260:", nullptr));
        buttonAddAnimal->setText(QCoreApplication::translate("IgoninDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        buttonChangeAnimal->setText(QCoreApplication::translate("IgoninDialog", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        buttonDeleteAnimal->setText(QCoreApplication::translate("IgoninDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        buttonCloseDialog->setText(QCoreApplication::translate("IgoninDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        checkBoxPoisonous->setText(QCoreApplication::translate("IgoninDialog", "\320\257\320\264\320\276\320\262\320\270\321\202\320\276\321\201\321\202\321\214", nullptr));
        buttonComplete->setText(QCoreApplication::translate("IgoninDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IgoninDialog: public Ui_IgoninDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IGONINDIALOG_H
