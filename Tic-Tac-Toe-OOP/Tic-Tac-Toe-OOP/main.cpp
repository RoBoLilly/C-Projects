//
//  main.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 9/28/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteButton.hpp"
#include "Text.hpp"
#include "Background.hpp"
#include "ButtonArray.hpp"
#include "StateArray.hpp"
#include "WinPrimer.hpp"
#include "StateIndicator.hpp"
#include "GameStateMachine.hpp"
#include "GameManager.hpp"
#include "DrawManager.hpp"
#include "Checker.hpp"


const int WIDTH = 700; // Start Width
const int HIGHT = 600; // Start Hight
int main(int argc, const char * argv[])
{
    sf::RenderWindow window( sf::VideoMode( WIDTH, HIGHT ), "- Tic Tac Toe -" );
    Text text("Arial.ttf");
    Background bg(WIDTH, HIGHT);
    ButtonArray buttonArray("Tic-Tac-Toe.png");
    StateArray stateArray;
    WinPrimer winPrimer;
    StateIndicator stateIndicator(buttonArray.getTexture());
    GameStateMachine gs(PLAY);
    TileState placeState = X; // Inital State 
    GameManager GM(text, bg, buttonArray, stateArray, winPrimer, stateIndicator, gs, placeState);
    DrawManager drawManager(window, GM);
    Checker checker(GM);
    
    while ( window.isOpen() ) // Main Loop - |
    {
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
                    if (e.key.code == sf::Keyboard::R) {
                        GM.reset();
                    }
                    
                } break;
                case sf::Event::MouseButtonPressed: {
                    if (gs.state != PLAY) {
                        GM.reset();
                    } else {
                        checker.buttonPress(window);
                        
                        if (checker.winCheck()) {
                        } else {
                            if (!checker.catsCheck()) {
                                gs = DRAW;
                                stateIndicator.get()->setTextureRect(sf::IntRect(0, 0, 128, 128));
                                stateIndicator.get()->setColor(sf::Color::Red);
                            }
                        }
                        GM.updateButtonSprite();
                    }
                    break;
                }
            }
            
        }
        
        
        window.clear(sf::Color::Black);
        drawManager.draw();
        window.display();
    }
    return 0;
}
