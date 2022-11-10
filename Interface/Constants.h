#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// Размер главного окна
const int windowWidth = 1280; // ширина
const int windowHeight = 720; // высота

float radius = 20;            // радиус круга
int fontSize = radius/1.5;    // размер шрифта
int maxFPS = 15;              // максимальная частота обновления изображения
bool darkTheme;               // включение темной темы
int borderSize = 3;           // размер границы
sf::Font font;                // шрифт

//int borderSize = radius / 10; //размер границы

sf::Color borderColor = sf::Color(128,128,128); // цвет обводки круга
sf::Color connectionColor;                      // цвет соединений между кругами
sf::Color textColor = sf::Color(255,255,255);   // цвет теккста
sf::Color backgroundColor;                      // цвет фона

sf::Color black = sf::Color(80, 80, 80);
sf::Color red = sf::Color(200, 0, 0);
sf::Color green = sf::Color(0, 220, 0);

int pi = 3.1415926535897932384626433832795;