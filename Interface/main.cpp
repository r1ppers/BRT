#include <SFML/Graphics.hpp>
#include <iostream>

#include "Classes.h"
#include "Constants.h"
#include "Functions.h"



int main()
{
    // Cглаживание ступенек пикселей
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; 

    // Создаем главное окно приложения
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "Red-Black Tree",
        sf::Style::Titlebar | sf::Style::Close, settings);

    // Устранение разрыва кадров
    window.setVerticalSyncEnabled(true);

    // Создаем переменную таймера (нужен для плавной анимации)
    sf::Clock clock;
    float time;
    int fps = 0;

    // Темная тема
    bool turnOnDarkTheme = true;

    // Обновление констант
    UpdateConstants(turnOnDarkTheme);

    // Главный цикл приложения
    while (window.isOpen())
    {
        UpdateConstants(turnOnDarkTheme);
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // Главные объекты
        BallNode ballBlack = BallNode(fps, black, &font, true);
        BallNode ballRed =   BallNode(fps - 5, red, &font);
        BallNode ballGreen = BallNode(fps - 10, green, &font);

        // Определение темы для отображения
        if (turnOnDarkTheme) SetDarkTheme();
        else SetLightTheme();

        // Очистка
        window.clear(backgroundColor);

        time = clock.getElapsedTime().asMilliseconds(); // время кадра
        fps = 1000 / time;                              // кол-во кадров в секунду
        clock.restart();

        // Тут будут вызываться функции обновления и отрисовки объектов
        window.setFramerateLimit(maxFPS); // ограничение частоты кадров

        ballBlack.DrawChilds(ballGreen, ballRed, &window);

        ShowFPS(fps,&window);
        
        // Отрисовка
        window.display();
    }

    return EXIT_SUCCESS;
}
