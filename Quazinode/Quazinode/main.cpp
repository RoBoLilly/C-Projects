//
//  main.cpp
//  Quazinode
//
//  Created by Lilly Fiorino on 9/17/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.hpp"
#include "SpriteButton.hpp"

const int WIDTH = 500*2;
const int HIGHT = 300*2;

int foo() { return 128; }

int main(int argc, const char * argv[])
{
    sf::RenderWindow window( sf::VideoMode( WIDTH, HIGHT ), "- QuaZiNodE -" );
    sf::Event e; // Event Manager - |
    while ( window.pollEvent(e) ) {
        switch (e.type) {
            default:
                break;
            case sf::Event::Closed: {
                window.close();
            } break;
            case sf::Event::KeyPressed:
            {
                if (e.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            } break;
            case sf::Event::MouseButtonPressed: {
            } break;
        }
    }
    std::cout << foo() << std::endl;
    window.close();
    return 0;
}
