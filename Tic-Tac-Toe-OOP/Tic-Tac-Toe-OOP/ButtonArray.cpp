//
//  ButtonArray.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "ButtonArray.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

ButtonArray::ButtonArray(std::string path)
{
    if (!buttonTexture.loadFromFile(path)) {
        std::cerr << "Button Texture Fail" << std::endl;
    }
    buttonTexture.setSmooth(true); // Turns Anti-Aliasing ON
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            buttons[i][j].setTexture(buttonTexture);
            buttons[i][j].setPos(sf::Vector2f(40 + 140*i, 40 + 140*j));
            buttons[i][j].setSize(sf::Vector2f(128, 128));
            buttons[i][j].setColor(sf::Color(239, 70, 128));
        }
    }
}

SpriteButton ButtonArray::getButton(int i, int j) { return buttons[i][j]; }

sf::Texture* ButtonArray::getTexture() { return &buttonTexture; }
