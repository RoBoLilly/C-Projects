//
//  Text.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Text.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Text::Text(std::string path)
{
    if (!font.loadFromFile(path)) {
        std::cerr<<"/// - FONT ERROR - ///"<<std::endl;
    }
    Cats.setPosition(510, 240);
    Cats.setFont(font);
    Cats.setString("DRAW");
    Cats.setCharacterSize(40);
    Cats.setColor(sf::Color::Red);
    Cats.setStyle(sf::Text::Bold);
    
    WinO.setPosition(50, 460);
    WinO.setFont(font);
    WinO.setString("O Won!");
    WinO.setCharacterSize(100);
    WinO.setColor(sf::Color(239, 70, 128));
    
    WinX.setPosition(50, 460);
    WinX.setFont(font);
    WinX.setString("X Won!");
    WinX.setCharacterSize(100);
    WinX.setColor(sf::Color(239, 70, 128));
}

sf::Text Text::getCats() { return Cats; }

sf::Text Text::getWinX() { return WinX; }

sf::Text Text::getWinO() { return WinO; }
