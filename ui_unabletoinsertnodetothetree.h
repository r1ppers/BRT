/********************************************************************************
** Form generated from reading UI file 'unabletoinsertnodetothetree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNABLETOINSERTNODETOTHETREE_H
#define UI_UNABLETOINSERTNODETOTHETREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UnableToInsertNodeToTheTree
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *UnableToInsertNodeToTheTree)
    {
        if (UnableToInsertNodeToTheTree->objectName().isEmpty())
            UnableToInsertNodeToTheTree->setObjectName(QString::fromUtf8("UnableToInsertNodeToTheTree"));
        UnableToInsertNodeToTheTree->resize(380, 110);
        UnableToInsertNodeToTheTree->setMinimumSize(QSize(380, 110));
        UnableToInsertNodeToTheTree->setMaximumSize(QSize(380, 110));
        UnableToInsertNodeToTheTree->setStyleSheet(QString::fromUtf8("#UnableToInsertNodeToTheTree {\n"
"background-color: #131313;\n"
"color: #ffffff;\n"
"border-radius: 5px;\n"
"}"));
        label = new QLabel(UnableToInsertNodeToTheTree);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 361, 21));
        label->setStyleSheet(QString::fromUtf8("color: #ffffff;"));
        pushButton = new QPushButton(UnableToInsertNodeToTheTree);
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

        retranslateUi(UnableToInsertNodeToTheTree);

        QMetaObject::connectSlotsByName(UnableToInsertNodeToTheTree);
    } // setupUi

    void retranslateUi(QDialog *UnableToInsertNodeToTheTree)
    {
        UnableToInsertNodeToTheTree->setWindowTitle(QApplication::translate("UnableToInsertNodeToTheTree", "\320\236\321\210\320\270\320\261\320\272\320\260!", nullptr));
        label->setText(QApplication::translate("UnableToInsertNodeToTheTree", "\320\235\320\265 \321\203\320\264\320\260\320\273\320\276\321\201\321\214 \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202 \320\262 \320\264\320\265\321\200\320\265\320\262\320\276, \320\277\320\276\321\201\320\272\320\276\320\273\321\214\320\272\321\203 \320\276\320\275 \321\203\320\266\320\265 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275!", nullptr));
        pushButton->setText(QApplication::translate("UnableToInsertNodeToTheTree", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnableToInsertNodeToTheTree: public Ui_UnableToInsertNodeToTheTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNABLETOINSERTNODETOTHETREE_H
