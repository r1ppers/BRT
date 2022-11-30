/********************************************************************************
** Form generated from reading UI file 'valueoutofrange.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALUEOUTOFRANGE_H
#define UI_VALUEOUTOFRANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ValueOutOfRange
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *ValueOutOfRange)
    {
        if (ValueOutOfRange->objectName().isEmpty())
            ValueOutOfRange->setObjectName(QString::fromUtf8("ValueOutOfRange"));
        ValueOutOfRange->resize(380, 110);
        ValueOutOfRange->setMinimumSize(QSize(380, 110));
        ValueOutOfRange->setMaximumSize(QSize(380, 110));
        ValueOutOfRange->setStyleSheet(QString::fromUtf8("background: #131313;"));
        pushButton = new QPushButton(ValueOutOfRange);
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
        label = new QLabel(ValueOutOfRange);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 341, 16));
        label->setStyleSheet(QString::fromUtf8("color: #ffffff;"));

        retranslateUi(ValueOutOfRange);

        QMetaObject::connectSlotsByName(ValueOutOfRange);
    } // setupUi

    void retranslateUi(QDialog *ValueOutOfRange)
    {
        ValueOutOfRange->setWindowTitle(QApplication::translate("ValueOutOfRange", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ValueOutOfRange", "OK", nullptr));
        label->setText(QApplication::translate("ValueOutOfRange", "\320\222\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\264\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 \320\262 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\265 \320\276\321\202 -9999 \320\264\320\276 9999", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ValueOutOfRange: public Ui_ValueOutOfRange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALUEOUTOFRANGE_H
