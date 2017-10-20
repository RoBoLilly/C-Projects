//
//  StateIndicator.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "StateIndicator.hpp"
#include <SFML/Graphics.hpp>

StateIndicator::StateIndicator(sf::Texture* texture)
{
    m_texture = texture;
    stateIndicator.setTexture(*m_texture);
    stateIndicator.scale(1.2, 1.2);
    stateIndicator.setPosition(500, 60);
    stateIndicator.setTextureRect(sf::IntRect(0, 0, 128, 128));
    stateIndicator.setColor(sf::Color(239, 70, 128));
}

sf::Sprite* StateIndicator::get() { return &stateIndicator; }
