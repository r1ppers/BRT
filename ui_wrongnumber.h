/********************************************************************************
** Form generated from reading UI file 'wrongnumber.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONGNUMBER_H
#define UI_WRONGNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WrongNumber
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *WrongNumber)
    {
        if (WrongNumber->objectName().isEmpty())
            WrongNumber->setObjectName(QString::fromUtf8("WrongNumber"));
        WrongNumber->resize(380, 110);
        WrongNumber->setMinimumSize(QSize(380, 110));
        WrongNumber->setMaximumSize(QSize(380, 110));
        WrongNumber->setStyleSheet(QString::fromUtf8("#WrongNumber {\n"
"background-color: #131313;\n"
"color: #ffffff;\n"
"border-radius: 5px;\n"
"}"));
        pushButton = new QPushButton(WrongNumber);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 80, 80, 21));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"	background-color: rgb(38, 38, 38);\n"
"	border: none;\n"
"	color:#ffffff;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#pushButton:hover{\n"
"	border: 1px solid #393939\n"
"}\n"
"\n"
"#pushButton:pressed{\n"
"	background-color: #393939;\n"
"}"));
        label = new QLabel(WrongNumber);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 281, 16));
        label->setStyleSheet(QString::fromUtf8("color: #ffffff;"));

        retranslateUi(WrongNumber);

        QMetaObject::connectSlotsByName(WrongNumber);
    } // setupUi

    void retranslateUi(QDialog *WrongNumber)
    {
        WrongNumber->setWindowTitle(QApplication::translate("WrongNumber", "\320\236\321\210\320\270\320\261\320\272\320\260!", nullptr));
        pushButton->setText(QApplication::translate("WrongNumber", "OK", nullptr));
        label->setText(QApplication::translate("WrongNumber", "\320\222\320\262\320\265\320\264\320\265\320\275\320\276 \320\275\320\265\320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WrongNumber: public Ui_WrongNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONGNUMBER_H
