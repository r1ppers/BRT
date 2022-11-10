#include <SFML/Graphics.hpp>
#include <iostream>

#include "Classes.h"
#include "Constants.h"
#include "Functions.h"



int main()
{
    // C���������� �������� ��������
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; 

    // ������� ������� ���� ����������
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "Red-Black Tree",
        sf::Style::Titlebar | sf::Style::Close, settings);

    // �������������� ������� ������
    window.setVerticalSyncEnabled(true);

    // ������� ���������� ������� (����� ��� ������� ��������)
    sf::Clock clock;
    float time;
    int fps = 0;

    // ������ ����
    bool turnOnDarkTheme = true;

    // ���������� ��������
    UpdateConstants(turnOnDarkTheme);

    // ������� ���� ����������
    while (window.isOpen())
    {
        UpdateConstants(turnOnDarkTheme);
        // ������������ ������� � �����
        sf::Event event;
        while (window.pollEvent(event))
        {
            // ����� �������� ������� ���� ���� ����� ����������� �� ������� �� Escape
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // ������� �������
        int x = 150;
        int y = 150;
        
        BallNode ballBlack = BallNode(fps, black, &font, true);
        BallNode ballRed =   BallNode(fps - 5, red, &font);
        BallNode ballGreen = BallNode(fps - 10, green, &font);

        // ����������� ���� ��� �����������
        if (turnOnDarkTheme) SetDarkTheme();
        else SetLightTheme();

        // �������
        window.clear(backgroundColor);

        time = clock.getElapsedTime().asMilliseconds(); // ����� �����
        fps = 1000 / time;                              // ���-�� ������ � �������
        clock.restart();

        // ��� ����� ���������� ������� ���������� � ��������� ��������
        window.setFramerateLimit(maxFPS); // ����������� ������� ������

        /*
        std::cout << "\n\n=-=-=-=-=-=-=-=-=[�������]=-=-=-=-=-=-=-=-=" << std::endl;
        BallNode::DrawConnection(ballBlack, ballRed, &window);
        std::cout << "=-=-=-=-=-=-=-=-=[�������]=-=-=-=-=-=-=-=-=" << std::endl;
        BallNode::DrawConnection(ballBlack, ballGreen, &window);
        ballBlack.Draw(&window);
        ballRed.Draw(&window);
        ballGreen.Draw(&window);
        */

        ballBlack.DrawChilds(ballGreen, ballRed, &window);

        //BallNode::DrawLeft(ballBlack,ballRed, &window);
        //BallNode::DrawRight(ballBlack, ballGreen, &window);
        ShowFPS(fps,&window);
        
        // ���������
        window.display();
    }

    return EXIT_SUCCESS;
}