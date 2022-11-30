#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once
#include <QPainter>
#include <QDebug>
#include <QPainterPath>
#include <QStatusBar>

#include "Line.h"
#include "Constants.h"

#include "RBTree/RBTreeFunctions.h"
#include "RBTree/RBTree.h"

#include <cmath>

enum Child { Left, Right };



class Circle
{
private:
    //координаты центра
    //int x = 0;
    //int y = 0;

    Node* node;
    Node* root;
    RBTree* tree;

    int windowWidth = 0;


    QColor backgroundColor = Qt::blue; //цвет фона
    QColor borderColor = Qt::green;    //цвет обводки

    std::string data;
    QPainterPath text;

    static Node* GetGrandparent(Node* node)
    {
        if (node)
            if (node->parent)
                if (node->parent->parent)
                    return node->parent->parent;
        return nullptr;
    }

    int GetDepth()
    {
        Node* temp = node;
        node->depth = 1;
        if (temp == nullptr)
        {
            qDebug() << "node is null";
        }
        else
        {
            while (temp->parent != nullptr)
            {
                temp = temp->parent;
                node->depth++;
            }
        }
        return node->depth;
    }

    static void GetFullDepth(Node* node)
    {
        if (node)
        {
            fullDepth = (node->depth < fullDepth) ? fullDepth : node->depth;
            GetFullDepth(node->left);
            GetFullDepth(node->right);
        }
    }

    static int GetMinDistance()
    {
        //return (1280 - radius * 5) / (pow(2, (fullDepth)) - 1);
        return radius * fullDepth;
    }

    static void DefineHeadDistance(RBTree* tree)
    {
        Node* root = tree->getRoot();
        GetFullDepth(root);
        root->sideDistance = GetMinDistance() * fullDepth;
    }

    static void Organize(Node* node)
    {
        if (node)
        {
            if (node->left)
            {
                node->left->sideDistance = node->sideDistance / 2;
                Organize(node->left);
            }
            if (node->right)
            {
                node->right->sideDistance = node->sideDistance / 2;
                Organize(node->right);
            }
        }
    }

    static void FindMinX(Node* node)
    {
        if (node)
        {
            minPosX = min(minPosX, node->position.x());
            if (node->left)  FindMinX(node->left);
            if (node->right) FindMinX(node->right);
        }
    }


public:
    static void Correct(RBTree* tree)
    {
        FindMinX(tree->getRoot());
        if (minPosX < radius)
            tree->getRoot()->position = QPoint(tree->getRoot()->position.x() + fabs(minPosX) + radius, tree->getRoot()->position.y());
        minPosX = 1280;
    }

    QPainter* painter;

    Circle()
    {

    }

    Circle(Node* node, QPainter* painter, int windowWidth, RBTree* tree)
    {
        this->tree = tree;
        this->root = tree->getRoot();

        this->node = node;

        if (node == nullptr)
        {
            return;
        }
        else
        {
            if (node->color == RBColors::BLACK)
                this->backgroundColor = Black;
            else if (node->color == RBColors::RED)
                this->backgroundColor = Red;

            this->data = to_string(node->data);
            this->borderColor = lineColor;
            this->windowWidth = windowWidth;

            if (node->parent == nullptr)
                SetPosition(QPoint(windowWidth / 2, parentsDistance));

            this->node->depth = GetDepth();
            this->painter = painter;

            SetSideDistance(this->tree);
        }
    }

    void SetSideDistance(RBTree* tree)
    {
        //работает, но плохо
        //this->node->sideDistance = windowWidth / 3 / this->node->depth;

        //в процессе
        /*
        GetFullDepth(root);

        
        int minimalDistance = GetMinDistance();

        float tempDistance = minimalDistance;
        if (fullDepth > 3)
        {
            tempDistance *= (fullDepth / 2);
            minimalDistance = round(tempDistance);
        }

        if (fullDepth == this->node->depth)
            this->node->sideDistance = minimalDistance;
        else
            this->node->sideDistance = (fullDepth - this->node->depth) * minimalDistance;

        auto temp = this->node;
        while (temp->parent)
        {
            this->node->parent->sideDistance = this->node->sideDistance * 2;
            temp = temp->parent;
        }
        */
        
        /*
        int minimalDistance = (1280 - radius * 3) / (pow(2, (fullDepth-1)) - 1);
        int tempDistance;
        if (node->depth == 1)
            node->sideDistance = windowWidth / 4;
        else
        {
            tempDistance = minimalDistance;
            node->sideDistance = minimalDistance;


            Node* temp = node;

            if (temp && temp->parent)
                while (temp->parent)
                {
                    temp->parent->sideDistance = temp->sideDistance * 2;
                    temp = temp->parent;
                }
        }
        */

        Node* rootNode = tree->getRoot();

        DefineHeadDistance(tree);
        Organize(rootNode);

        /*
        qDebug() << "-------------------";
        qDebug() << "depth = " << this->node->depth;
        qDebug() << "full depth = " << fullDepth;
        qDebug() << "side distance = " << this->node->sideDistance;
        */
    }

    //Получить координаты
    QPoint GetPosition()
    {
        return QPoint(this->node->position.x(), this->node->position.y());
        //return QPoint(x, y);
    }

    //Установить цвет фона
    void SetBackgroundColor(QColor backgroundColor)
    {
        this->backgroundColor = backgroundColor;
    }

    //Получить цвет фона
    QColor GetBackgroundColor()
    {
        return backgroundColor;
    }

    //Установить цвет обводки
    void SetBorderColor(QColor borderColor)
    {
        this->borderColor = borderColor;
    }

    //Получить цвет обводки
    QColor GetBorderColor()
    {
        return borderColor;
    }

    //Установить координаты
    void SetPosition(QPoint position)
    {
        //this->x = position.x();
        //this->y = position.y();
        if (this->node->depth == 1)
            node->position = QPoint(position.x() - (offsetX / (this->node->depth)), position.y());
        else
            node->position = QPoint(position.x() - (offsetX / (this->node->depth + radius*2)), position.y());
    }

    //Нарисовать
    void Draw()
    {
        int fontSizeTemp = fontSize;

        if (data.length() > 3)
        {
            fontSizeTemp = fontSize - data.length();
        }

        auto posX = GetPosition().x() - radius / 2 + fontSize / 2 - ((0.35 * fontSize) * (data.length() - 1));
        auto posY = GetPosition().y() + radius / 4;

        QPoint pos = QPoint(posX, posY);
        QFont tempFont = QFont(fontName, fontSizeTemp);

        text.addText(pos, tempFont, QString::fromStdString(data));

        //Контур
        QPen pen;
        pen.setColor(lineColor);
        pen.setWidth(lineWidth);
        painter->setPen(pen);

        //Заливка
        QBrush brush;
        brush.setColor(backgroundColor);
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);

        int ellipsePosX = GetPosition().x() - radius + lineWidth / 2;
        int ellipsePosY = GetPosition().y() - radius + lineWidth / 2;

        painter->drawEllipse(ellipsePosX, ellipsePosY, radius * 2, radius * 2);

        //Текст
        tempFont.setBold(true);
        pen.setColor(textColor);
        painter->setPen(pen);
        painter->setFont(tempFont);

        painter->drawText(pos, data.c_str());

    }

    //Нарисовать круг ребенка
    void DrawChild(Child type)
    {
        Node* child;

        //Node* grandparent = node->parent->parent;
        Circle childCircle;

        int parentPosX = GetPosition().x();
        int parentPosY = GetPosition().y();

        int childPosX = 0;
        int childPosY = parentPosY + parentsDistance;
        int grandparentPosX = 0;
        /*
        Node* grandparent = GetGrandparent(node);

        if (grandparent)
            grandparentPosX = grandparent->position.x();
        */

        if (type == Child::Left && node->left != nullptr)
        {
            child = node->left;
            childCircle = Circle(child, painter, windowWidth, tree);
            //childCircle.SetSideDistance();
            childPosX = parentPosX - childCircle.node->sideDistance;
        }
        else if (type == Child::Right && node->right != nullptr)
        {
            child = node->right;
            childCircle = Circle(child, painter, windowWidth, tree);
            //childCircle.SetSideDistance();
            childPosX = parentPosX + childCircle.node->sideDistance;
        }

        childCircle.SetPosition(QPoint(childPosX, childPosY));
        Line::Draw(parentPosX, parentPosY, childPosX, childPosY, painter);
        Draw();
        childCircle.Draw();
    }

    //Нарисовать дерево
    void DrawTree()
    {
        Node* temp = node;
        if (temp)
        {
            Circle tempCircle = Circle(temp, painter, windowWidth, tree);
            tempCircle.Draw();
         
            if (tempCircle.node->left != nullptr)
            {
                tempCircle.DrawChild(Child::Left);
                Circle nodeLeft = Circle(tempCircle.node->left, painter, windowWidth, tree);
                nodeLeft.DrawTree();
            }
            if (tempCircle.node->right != nullptr)
            {
                tempCircle.DrawChild(Child::Right);
                Circle nodeRight = Circle(tempCircle.node->right, painter, windowWidth, tree);
                nodeRight.DrawTree();
            }
        }
    }
};


#endif // CIRCLE_H
