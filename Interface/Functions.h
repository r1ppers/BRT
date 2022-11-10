#pragma once
#include "Constants.h"
void ShowFPS(int fps, sf::RenderWindow* window)
{
    sf::Text strFPS;
    sf::RectangleShape background;

    strFPS.setFont(font);
    strFPS.setFillColor(green);
    strFPS.setCharacterSize(12);
    strFPS.setPosition(0, 0);
    strFPS.setString("FPS: " + std::to_string(fps));
    strFPS.setOutlineThickness(0.5);
    strFPS.setOutlineColor(green);

    background.setFillColor(sf::Color(0, 0, 0, 128));
    background.setSize(sf::Vector2f(50, 15));

    window->draw(background);
    window->draw(strFPS);
}

int UpdateConstants(bool darkThemeTurnedOn = false)
{
    // Темная тема
    darkTheme = darkThemeTurnedOn;

    if (darkTheme)
        backgroundColor = sf::Color(32, 32, 32);
    else
        backgroundColor = sf::Color(255, 255, 255);

    //borderColor = textColor;
    connectionColor = textColor;

    // Подключение шрифта текста
    if (!font.loadFromFile("resources/consolas.ttf"))
        return EXIT_FAILURE;
}

bool SetLightTheme()
{
    darkTheme = false;
    UpdateConstants(darkTheme);
    return darkTheme;
}

bool SetDarkTheme()
{
    darkTheme = true;
    UpdateConstants(darkTheme);
    return darkTheme;
}
