#pragma once

#include <QPainter>
#include <cmath>

//Цвета
QColor Red        = QColor(192, 0, 0);
QColor Black      = QColor(13, 13, 13);
QColor BlueBorder = QColor(64, 64, 192);   // цвет найденного узла
QColor textColor  = QColor(192, 192, 192); // цвет текста
QColor lineColor  = QColor(128, 128, 128); // цвет линии

enum RBColors { RED, BLACK };
enum NodeBorderColor { DEFAULT, FOUND };

//Шрифт
const int fontSize = 18;
const QString fontName = "Arial";
QFont font(fontName, fontSize);

const int lineWidth = 3;                  //толщина линии
const int radius = 25;                    //радиус круга
const int parentsDistance = radius * 3;   //высота между кругами

int fullDepth = 1;

int offsetX = 0;
int offsetY = 0;
int maxOffsetX = 0;
int maxOffsetY = 0;

int minPosX = 1280;
int minPosY = 720;

//Node* root = new Node(0,RBColors::RED);

int log(int a, int b)
{
	return log2(b) / log2(a);
}

int GetSideOffset(int widowWidth, int depth)
{
	return widowWidth / log(2, 1);
}