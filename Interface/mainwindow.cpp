#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QStatusBar>
#include <QScrollBar>

#include <cmath>
#include <string>

//Отрисовка дерева
#include "Constants.h"
#include "Circle.h"
#include "Line.h"

//Реализация дерева
#include "RBTree/RBTreeFunctions.h"
#include "RBTree/RBTree.h"

//Диалоговые окна
#include "unabletoinsertnodetothetree.h"
#include "wrongnumber.h"
#include "unabletoremovenodefromthetree.h"
#include "selectanaction.h"
#include "valueoutofrange.h"


int amountOfNodes = 0;
int arrNodes[512];

bool insertNode = false;
bool removeNode = false;
int inputData = -99999;

std::string deb = "";

RBTree tree;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tree = RBTree();
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(-2147483648, 2147483647, this));
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool StrIsValidNum(std::string str)
{
    if (!strcmp(str.c_str(), "") ||              // строка пустая
        str[0] - '0' == -5 ||                    //строка начинается с +
        str[0] - '0' == -3 && str.length() == 1) // строка является знаком минуса
    {
        WrongNumber wrongNumber;
        wrongNumber.setModal(true);
        wrongNumber.exec();
        return false;
    }
    int data = stoi(str);

    if (data <= -10000 || data >= 10000)
    {
        ValueOutOfRange valueOutOfRange;
        valueOutOfRange.setModal(true);
        valueOutOfRange.exec();
        return false;
    }

    return true;
}

void SetMaxOffset(Node* node)
{
    if (node)
    {
        maxOffsetX = max(maxOffsetX, (int)fabs(tree.getRoot()->position.x() - node->position.x()));
        if (node->left)  SetMaxOffset(node->left);
        if (node->right) SetMaxOffset(node->right);
    }
}


void MainWindow::on_insertButton_clicked()
{
    if (!insertNode && !removeNode)
    {
        SelectAnAction selectAnAction;
        selectAnAction.setModal(true);
        selectAnAction.exec();
    }

    std::string strData = ui->lineEdit->text().toStdString();

    if (StrIsValidNum(strData))
    {
        inputData = stoi(strData);
        if (insertNode)
        {
            amountOfNodes++;

            bool result = tree.Insert(inputData);

            if (!result)
            {
                UnableToInsertNodeToTheTree unableToInsertNodeToTheTree;
                unableToInsertNodeToTheTree.setModal(true);
                unableToInsertNodeToTheTree.exec();
            }
            else
            {
                qDebug() << "root data: " << tree.getRoot()->data;
                //SetMaxOffset(tree.getRoot());
                //qDebug() << "max offset: " << maxOffsetX;
                
            }
        }
        else if (removeNode)
        {
            amountOfNodes--;

            bool result = tree.Remove(inputData);
            if (!result)
            {
                UnableToRemoveNodeFromTheTree unableToRemoveNodeFromTheTree;
                unableToRemoveNodeFromTheTree.setModal(true);
                unableToRemoveNodeFromTheTree.exec();
            }
            else
            {
                qDebug() << inputData << " succesfully removed";
            }
        }
    }
    this->repaint();
    this->repaint();
}


void MainWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.begin(this);
    //------------------------------[Рисование синусоиды]------------------------------//
    /*
    QColor color = QColor(255, 0, 0);
    painter.setPen(QPen(color, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
    int x1 = 0;
    int y1 = 300;
    int step = 1;
    int scale = 5;
    for (int x2 = x1 + step; x2 < 100 * scale; x2 += step)
    {
        int x1New = (x2 - step);
        int y1New = sin(x1New) * scale + y1;
        int y2 = scale * sin(x2) + y1;
        auto x2New = x2;
        painter.drawLine(x1New * scale, y1New, x2 * scale, y2);
        //painter.drawRect(x2*scale, y2, 1, 1);
    }
    */
    //---------------------------------------------------------------------------------//
    
    auto scrollBarX = ui->horizontalScrollBar;
    auto scrollBarY = ui->verticalScrollBar;
    scrollBarX->setMaximum(maxOffsetX);
    scrollBarX->setMinimum(-maxOffsetX);
    scrollBarY->setMaximum(maxOffsetY);
    
    offsetX = scrollBarX->value();
    offsetY = scrollBarY->value();
    
    qDebug() << "offsetX = " << offsetX;
    qDebug() << "offsetY = " << offsetY;

    //Антиалиасинг (сглаживание)
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    
    Node* root = tree.getRoot();

    Circle headCircle = Circle(root, &painter, width(), &tree);
    
    if (headCircle.painter != nullptr)
    {
        headCircle.DrawTree();
        Circle::Correct(&tree);
        headCircle.DrawTree();
    }
    

    Node* rootNode = tree.getRoot();
    Node* node = tree.Search(inputData);
    int windowWidth = width();
    if (inputData != -99999)
    {
        if (fabs(rootNode->position.x() - node->position.x()) > windowWidth / 3)
        {
            maxOffsetX = fabs(rootNode->position.x() - fabs(node->position.x())) - windowWidth / 3;
            qDebug() << "rootNode->position.x() = " << rootNode->position.x();
            qDebug() << "node->position.x() = " << node->position.x();
            qDebug() << "max offset x = " << maxOffsetX;
        }
    }

    painter.end();
}


void MainWindow::on_insertRadioButton_toggled(bool checked)
{
    //qDebug() << "insert";
    removeNode = false;
    insertNode = true;

}


void MainWindow::on_removeRadioButton_toggled(bool checked)
{
    //qDebug() << "remove";
    insertNode = false;
    removeNode = true;

}


void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    this->repaint();
}


void MainWindow::on_lineEdit_editingFinished()
{
    //MainWindow::on_insertButton_clicked();
}


void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    this->repaint();
}

