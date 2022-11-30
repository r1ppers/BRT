/********************************************************************************
** Form generated from reading UI file 'chooseanaction.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEANACTION_H
#define UI_CHOOSEANACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChooseAnAction
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *ChooseAnAction)
    {
        if (ChooseAnAction->objectName().isEmpty())
            ChooseAnAction->setObjectName(QString::fromUtf8("ChooseAnAction"));
        ChooseAnAction->resize(380, 110);
        ChooseAnAction->setMinimumSize(QSize(380, 110));
        ChooseAnAction->setMaximumSize(QSize(380, 110));
        ChooseAnAction->setSizeIncrement(QSize(380, 110));
        ChooseAnAction->setStyleSheet(QString::fromUtf8("background-color: #131313;"));
        pushButton = new QPushButton(ChooseAnAction);
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
        label = new QLabel(ChooseAnAction);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 221, 16));
        label->setStyleSheet(QString::fromUtf8("color: white;"));

        retranslateUi(ChooseAnAction);

        QMetaObject::connectSlotsByName(ChooseAnAction);
    } // setupUi

    void retranslateUi(QDialog *ChooseAnAction)
    {
        ChooseAnAction->setWindowTitle(QApplication::translate("ChooseAnAction", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ChooseAnAction", "OK", nullptr));
        label->setText(QApplication::translate("ChooseAnAction", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseAnAction: public Ui_ChooseAnAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEANACTION_H
