//
//  Text.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Text {
private:
    sf::Font font;
    sf::Text Cats;
    sf::Text WinX;
    sf::Text WinO;
public:
    Text(std::string path);
    sf::Text getCats();
    sf::Text getWinX();
    sf::Text getWinO();
};

#endif /* Text_hpp */
