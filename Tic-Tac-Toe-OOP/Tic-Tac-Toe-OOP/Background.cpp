//
//  Background.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Background.hpp"
#include <SFML/Graphics.hpp>

Background::Background(const int WIDTH, const int HIGHT)
{
    W = WIDTH;
    H = HIGHT;
    m_background.setPosition(borderSize, borderSize);
    m_background.setSize(sf::Vector2f(W - 2*borderSize, H - 2*borderSize));
    m_background.setOutlineThickness(borderSize);
    m_background.setFillColor(sf::Color::Black); // Background Color
    m_background.setOutlineColor(sf::Color(239, 70, 128)); // Outline Color
}

sf::RectangleShape Background::getBackground() {
    return m_background;
}

void Background::setBorderSize(int size)
{
    borderSize = size;
    m_background.setPosition(borderSize, borderSize);
    m_background.setSize(sf::Vector2f(W - 2*borderSize, H - 2*borderSize));
    m_background.setOutlineThickness(borderSize);
}
