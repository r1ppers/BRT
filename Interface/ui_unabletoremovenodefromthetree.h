/********************************************************************************
** Form generated from reading UI file 'unabletoremovenodefromthetree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNABLETOREMOVENODEFROMTHETREE_H
#define UI_UNABLETOREMOVENODEFROMTHETREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UnableToRemoveNodeFromTheTree
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *UnableToRemoveNodeFromTheTree)
    {
        if (UnableToRemoveNodeFromTheTree->objectName().isEmpty())
            UnableToRemoveNodeFromTheTree->setObjectName(QString::fromUtf8("UnableToRemoveNodeFromTheTree"));
        UnableToRemoveNodeFromTheTree->resize(380, 110);
        UnableToRemoveNodeFromTheTree->setMinimumSize(QSize(380, 110));
        UnableToRemoveNodeFromTheTree->setMaximumSize(QSize(380, 110));
        UnableToRemoveNodeFromTheTree->setStyleSheet(QString::fromUtf8("#UnableToRemoveNodeFromTheTree {\n"
"background-color: #131313;\n"
"color: #ffffff;\n"
"border-radius: 5px;\n"
"}"));
        pushButton = new QPushButton(UnableToRemoveNodeFromTheTree);
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
        label = new QLabel(UnableToRemoveNodeFromTheTree);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 301, 16));
        label->setStyleSheet(QString::fromUtf8("color: #ffffff;"));

        retranslateUi(UnableToRemoveNodeFromTheTree);

        QMetaObject::connectSlotsByName(UnableToRemoveNodeFromTheTree);
    } // setupUi

    void retranslateUi(QDialog *UnableToRemoveNodeFromTheTree)
    {
        UnableToRemoveNodeFromTheTree->setWindowTitle(QApplication::translate("UnableToRemoveNodeFromTheTree", "\320\236\321\210\320\270\320\261\320\272\320\260!", nullptr));
        pushButton->setText(QApplication::translate("UnableToRemoveNodeFromTheTree", "OK", nullptr));
        label->setText(QApplication::translate("UnableToRemoveNodeFromTheTree", "\320\235\320\265 \321\203\320\264\320\260\320\273\320\276\321\201\321\214 \321\203\320\264\320\260\320\273\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnableToRemoveNodeFromTheTree: public Ui_UnableToRemoveNodeFromTheTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNABLETOREMOVENODEFROMTHETREE_H
