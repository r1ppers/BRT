/********************************************************************************
** Form generated from reading UI file 'selectanaction.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTANACTION_H
#define UI_SELECTANACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectAnAction
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectAnAction)
    {
        if (SelectAnAction->objectName().isEmpty())
            SelectAnAction->setObjectName(QString::fromUtf8("SelectAnAction"));
        SelectAnAction->resize(380, 110);
        SelectAnAction->setMinimumSize(QSize(380, 110));
        SelectAnAction->setMaximumSize(QSize(380, 110));
        SelectAnAction->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 19, 19);"));
        label = new QLabel(SelectAnAction);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 221, 16));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton = new QPushButton(SelectAnAction);
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

        retranslateUi(SelectAnAction);

        QMetaObject::connectSlotsByName(SelectAnAction);
    } // setupUi

    void retranslateUi(QDialog *SelectAnAction)
    {
        SelectAnAction->setWindowTitle(QApplication::translate("SelectAnAction", "Dialog", nullptr));
        label->setText(QApplication::translate("SelectAnAction", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265!", nullptr));
        pushButton->setText(QApplication::translate("SelectAnAction", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectAnAction: public Ui_SelectAnAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTANACTION_H
