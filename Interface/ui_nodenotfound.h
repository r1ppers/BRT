/********************************************************************************
** Form generated from reading UI file 'nodenotfound.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODENOTFOUND_H
#define UI_NODENOTFOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_nodeNotFound
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *nodeNotFound)
    {
        if (nodeNotFound->objectName().isEmpty())
            nodeNotFound->setObjectName(QString::fromUtf8("nodeNotFound"));
        nodeNotFound->resize(380, 110);
        nodeNotFound->setMinimumSize(QSize(380, 110));
        nodeNotFound->setMaximumSize(QSize(380, 110));
        nodeNotFound->setStyleSheet(QString::fromUtf8("background: #131313;"));
        label = new QLabel(nodeNotFound);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 221, 16));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton = new QPushButton(nodeNotFound);
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

        retranslateUi(nodeNotFound);

        QMetaObject::connectSlotsByName(nodeNotFound);
    } // setupUi

    void retranslateUi(QDialog *nodeNotFound)
    {
        nodeNotFound->setWindowTitle(QApplication::translate("nodeNotFound", "\320\236\321\210\320\270\320\261\320\272\320\260", nullptr));
        label->setText(QApplication::translate("nodeNotFound", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276!", nullptr));
        pushButton->setText(QApplication::translate("nodeNotFound", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nodeNotFound: public Ui_nodeNotFound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODENOTFOUND_H
