#pragma once
#include "Constants.h"
#include "Circle.h"
#include <QPainter>

class Line
{
private:
	QColor color = Black;
	//Circle* parent;
	//Circle* child;
	//QPainter* painter;

public:
	/*
	static void Draw(Circle parent, Circle child, QPainter* painter)
	{
		int x1 = parent.GetPosition().x();
		int y1 = parent.GetPosition().y();
		int x2 = child.GetPosition().x();
		int y2 = child.GetPosition().y();

		QPen pen;
		pen.setColor(lineColor);
		pen.setWidth(lineWidth);
		painter->setPen(pen);

		painter->drawLine(x1, y1, x2, y2);
	}
	*/

	static void Draw(int x1, int y1, int x2, int y2, QPainter* painter)
	{
		QPen pen;
		pen.setColor(lineColor);
		pen.setWidth(lineWidth);
		painter->setPen(pen);

		painter->drawLine(x1, y1, x2, y2);
	}
};