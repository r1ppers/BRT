#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// ������ �������� ����
const int windowWidth = 1280; // ������
const int windowHeight = 720; // ������

float radius = 20;            // ������ �����
int fontSize = radius/1.5;    // ������ ������
int maxFPS = 15;              // ������������ ������� ���������� �����������
bool darkTheme;               // ��������� ������ ����
int borderSize = 3;           // ������ �������
sf::Font font;                // �����

//int borderSize = radius / 10; //������ �������

sf::Color borderColor = sf::Color(128,128,128); // ���� ������� �����
sf::Color connectionColor;                      // ���� ���������� ����� �������
sf::Color textColor = sf::Color(255,255,255);   // ���� �������
sf::Color backgroundColor;                      // ���� ����

sf::Color black = sf::Color(80, 80, 80);
sf::Color red = sf::Color(200, 0, 0);
sf::Color green = sf::Color(0, 220, 0);

int pi = 3.1415926535897932384626433832795;