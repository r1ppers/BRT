/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *insertButton;
    QRadioButton *insertRadioButton;
    QRadioButton *removeRadioButton;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow {\n"
"background-color: #131313;\n"
"color: #ffffff;\n"
"border-radius: 5px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1070, 10, 181, 151));
        groupBox->setStyleSheet(QString::fromUtf8("border: 1px solid #393939;\n"
"color: white;\n"
"border-radius: 5px;"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 161, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 38, 38);\n"
"border: none;"));
        lineEdit->setMaxLength(5);
        lineEdit->setDragEnabled(true);
        insertButton = new QPushButton(groupBox);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(10, 120, 161, 21));
        insertButton->setStyleSheet(QString::fromUtf8("#insertButton{\n"
"	background-color: rgb(38, 38, 38);\n"
"	border: none;\n"
"}\n"
"\n"
"#insertButton:hover{\n"
"	border: 1px solid #393939\n"
"}\n"
"\n"
"#insertButton:pressed{\n"
"	background-color: #393939;\n"
"}"));
        insertRadioButton = new QRadioButton(groupBox);
        insertRadioButton->setObjectName(QString::fromUtf8("insertRadioButton"));
        insertRadioButton->setGeometry(QRect(10, 20, 84, 21));
        insertRadioButton->setStyleSheet(QString::fromUtf8("border: none;"));
        removeRadioButton = new QRadioButton(groupBox);
        removeRadioButton->setObjectName(QString::fromUtf8("removeRadioButton"));
        removeRadioButton->setGeometry(QRect(10, 40, 84, 21));
        removeRadioButton->setStyleSheet(QString::fromUtf8("border: none;"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 181, 151));
        label->setStyleSheet(QString::fromUtf8("background-color: #131313;\n"
"border-radius: 5px;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 91, 16));
        label_2->setStyleSheet(QString::fromUtf8("border:none;"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 60, 84, 21));
        radioButton->setStyleSheet(QString::fromUtf8("border: none;"));
        label->raise();
        lineEdit->raise();
        insertButton->raise();
        insertRadioButton->raise();
        removeRadioButton->raise();
        label_2->raise();
        radioButton->raise();
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(0, 701, 1261, 20));
        horizontalScrollBar->setStyleSheet(QString::fromUtf8(""));
        horizontalScrollBar->setMaximum(100);
        horizontalScrollBar->setSingleStep(1);
        horizontalScrollBar->setPageStep(1);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(1260, 0, 21, 701));
        verticalScrollBar->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1220, 170, 31, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"	color: #ffffff;\n"
"	background-color: rgb(38, 38, 38);\n"
"	border: none;\n"
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
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RBTree", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        insertButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        insertRadioButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeRadioButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
