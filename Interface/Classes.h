#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

#include <iostream>

#include "Constants.h"


class BallNode
{
private:
	

	sf::Color ballColor;        // цвет круга
	sf::RenderWindow* window;   // указатель на окно, нужен дл€ отрисовки
	sf::CircleShape mainCircle; // круг
	sf::Text nodeData;          // данные узла дл€ вывода
	sf::Vector2f currentPos;    // текуща€ позици€ в центре круга
	sf::Font currentFont;       // шрифт
	int data;                   // данные
	int offsetX = 0;            // отклонение строки данных дл€ значений меньше 100

	//sf::RectangleShape point;

public:

	// установка координат через целые числа
	void SetPosition(int x, int y)
	{
		
		mainCircle.setPosition(x - radius, y - radius);
		nodeData.setPosition(x - radius / 2 + offsetX, y - radius / 2);
		currentPos.x = x; // центрирование координат
		currentPos.y = y; // центрирование координат
	}
	
	// установление координат через вектор
	void SetPosition(sf::Vector2f position)
	{
		mainCircle.setPosition(position.x - radius, position.y - radius);
		nodeData.setPosition(position.x - radius / 2 + offsetX, position.y - radius / 2);
		currentPos.x = position.x; // центрирование координат
		currentPos.y = position.y; // центрирование координат
	}

	// получение текущей позиции через вектор
	sf::Vector2f GetPosition()
	{
		return currentPos;
	}

	BallNode(int data, sf::Color ballColor, sf::Font *font, bool isHead = false)
	{
		int x = 0, y = 0;
		//int x, y;
		if (isHead)
		{
			x = windowWidth / 2;
			y = radius * 2;
		}

		SetPosition(x, y);

		x -= radius; // центрирование координат
		y -= radius; // центрирование координат

		std::cout << "“екуща€ позици€ √ќЋќ¬џ: " << currentPos.x << "; " << currentPos.y << std::endl;

		/*
		point.setSize(sf::Vector2f(1, 1));
		point.setFillColor(green);
		point.setPosition(currentPos);
		*/


		this->data = data;
		this->ballColor = ballColor;
		this->currentFont = *font;
		
		std::string strData = std::to_string(data);
		
		
		for (int len = strData.length(); len < 3; len++)
			offsetX += fontSize/4;
		std::cout << "—мещение: " << offsetX << std::endl;
		

		mainCircle.setPosition(x, y);
		mainCircle.setRadius(radius);
		mainCircle.setFillColor(ballColor);
		mainCircle.setOutlineThickness(borderSize);
		mainCircle.setOutlineColor(borderColor);

		nodeData.setFont(*font);
		nodeData.setCharacterSize(fontSize);
		nodeData.setPosition(x + radius / 2 + offsetX, y + radius / 2);
		nodeData.setString(strData);
		nodeData.setFillColor(textColor);
		nodeData.setOutlineColor(textColor);
		nodeData.setOutlineThickness(0.5);

	}
	
	BallNode()
	{

	}

	// отрисовка узла в виде круга
	void Draw(sf::RenderWindow* window)
	{
		this->window = window;
		window->draw(mainCircle);
		window->draw(nodeData);
		//window->draw(point);
	}

	// отрисовка соединени€ между узлами
	void DrawConnection(BallNode child, sf::RenderWindow* window)
	{
		// координаты родительского узла
		auto Parent = GetPosition();
		// координаты потомка
		auto Child = child.GetPosition();

		setlocale(LC_ALL, "ru");
		//std::cout << "ѕозици€ родител€: " << Parent.x << ", " << Parent.y << std::endl;
		
		/*
		float length = pow(pow(xParent - xChild, 2) + pow(yParent - yChild, 2), 0.5); 
		float angleSin = fabs(yParent-yChild)/length; //в радианах

		float grad = 180 / pi;
		float angle = asin(angleSin) * grad;

		if (xChild < xParent)
			angle = -angle+180;

		//float angleCos = (xParent * xChild + yParent * yChild) /
		//	(pow(xParent * xParent + yParent * yParent, 0.5) * pow(xChild * xChild + yChild * yChild, 0.5));
		//float angle = 90 - acos(angleCos) * grad;
		

		// дебаг
		setlocale(LC_ALL, "ru");
		std::cout << " оординаты родител€: " << xParent << ", " << yParent << std::endl;
		std::cout << " оординаты потомка:  " << xChild << ", " << yChild << std::endl;
		std::cout << "ƒлина соединени€: " << length << std::endl;
		//std::cout << " осинус угла поворота: " << angleCos << std::endl;
		std::cout << "—инус угла поворота: " << angleSin << std::endl;
		std::cout << "”гол поворота в градусах: " << angle << std::endl;
		
		sf::Vector2f size(length, 5);

		sf::RectangleShape connection;
		connection.setFillColor(borderColor);
		connection.setSize(size);
		connection.setPosition(parent.GetPosition());
		connection.rotate(angle);

		window->draw(connection);
		*/

		/*
		я пыталс€ реализовать отрисовку линии при помощи поворота пр€моугольника, но у мен€ не вышло.
		ѕотому было прин€то решение использовать sf::Vertex, однако фигура получаетс€ толщиной в 1 пиксель.
		Ётой фигуре нельз€ придать бќльшую толщину, потому отрисовываетс€ несколько линий р€дом
		с малой разницей в начальных координатах. Ќачальные и конечные точки каждой из п€ти линий
		наход€тс€ в пор€дке числа 5 на игральной кости,	чтобы при повороте под любым углом толщина линии оставалась 3 пиксел€

		¬ итоге получаетс€ набор фигур имеющий следующий вид:

		                          о о
		                         / о
		                        / о о
		                       / / /
	                          / / /
		                     / / /
		                    / / /
		                   о о /
		                    о /
		                   о о

		*/

		auto firstPoint = sf::Vertex(Parent);
		auto lastPoint =  sf::Vertex(Child);

		firstPoint.color = borderColor;
		lastPoint.color =  borderColor;

		sf::Vertex line[5][2];
		for (int i = 0; i < 5; i++)
		{
			sf::Vertex elem[] = { firstPoint, lastPoint };
			line[i][0] = elem[0];
			line[i][1] = elem[1];
		}

		for (int i = 0; i < 2; i++)
		{
			line[1][i].position.x += 1;
			line[1][i].position.y += 1;

			line[2][i].position.x += 1;
			line[2][i].position.y -= 1;

			line[3][i].position.x -= 1;
			line[3][i].position.y -= 1;
			
			line[4][i].position.x -= 1;
			line[4][i].position.y += 1;
		}


		for (int i = 0; i < 5; i++)
			window->draw(line[i], 2, sf::Lines);

		// дебаг
		/*
		std::cout << "\n\n" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
				std::cout << "line[" << i << "][" << j << "] = {"
				<< line[i][j].position.x << ", " << line[i][j].position.y << "}" << std::endl;
			std::cout << std::endl;
		}
		*/
	}

	// отрисовка левого потомка
	void DrawLeft(int x, int y, BallNode left, sf::RenderWindow* window)
	{
		sf::Vector2f pos = currentPos;
		pos.x = x;
		pos.y = y;

		left.SetPosition(pos);

		DrawConnection(left, window);
		Draw(window);
		left.Draw(window);
	}

	// отрисовка правого потомка
	void DrawRight(int x, int y, BallNode right, sf::RenderWindow* window)
	{
		sf::Vector2f pos = currentPos;
		pos.x = x;
		pos.y = y;

		right.SetPosition(pos);

		DrawConnection(right, window);
		Draw(window);
		right.Draw(window);
	}

	// отрисовка обоих потомков
	void DrawChilds(BallNode left, BallNode right, sf::RenderWindow* window)
	{
		left.SetPosition(GetPosition().x * 1.0 / 2, GetPosition().y + radius * 2);
		right.SetPosition(GetPosition().x * 3.0 / 2, GetPosition().y + radius * 2);

		DrawConnection(left, window);
		DrawConnection(right, window);

		Draw(window);
		left.Draw(window);
		right.Draw(window);
	}
};