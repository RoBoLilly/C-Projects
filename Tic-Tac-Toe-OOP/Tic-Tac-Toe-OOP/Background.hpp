//
//  Background.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Background {
private:
    int W, H;
    sf::RectangleShape m_background;
    int borderSize = 8;
public:
    Background(const int WIDTH, const int HIGHT);
    sf::RectangleShape getBackground();
    void setBorderSize(int size);
};

#endif /* Background_hpp */
