#include "mainwindow.h"
#include <QTextCodec>
#include <QApplication>

#include <QScrollArea>
#include <QGroupBox>

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QApplication a(argc, argv);
    MainWindow w;
    /*
    QScrollArea* scroll = new QScrollArea;
    
    scroll->setParent(&w);
    QGroupBox* group = new QGroupBox;
    scroll->setWidget(group);

    scroll->setStyleSheet("QScrollBar::vertical {background - color: #131313; color: #131313}; ");

    group->setGeometry(0, 0, w.width(), w.height());
    scroll->setGeometry(0, 0, w.width(), w.height());
    */

    w.show();
    
    return a.exec();
}
