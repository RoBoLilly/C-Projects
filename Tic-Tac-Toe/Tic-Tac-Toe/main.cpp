//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Lilly Fiorino on 9/27/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteButton.hpp"

const int WIDTH = 700; // Start Width
const int HIGHT = 600; // Start Hight

int main(int argc, const char * argv[])
{
    sf::Font arial; // Load Font
    if (!arial.loadFromFile("Arial.ttf")) {
        std::cerr<<"/// - FONT ERROR - ///"<<std::endl;
        return EXIT_FAILURE;
    }
    
    sf::Text FailText; // Draw Gamestate Text
    FailText.setPosition(510, 240);
    FailText.setFont(arial);
    FailText.setString("DRAW");
    FailText.setCharacterSize(40);
    FailText.setColor(sf::Color::Red);
    FailText.setStyle(sf::Text::Bold);
    
    sf::Text WinOText; // O Wins Text
    WinOText.setPosition(50, 460);
    WinOText.setFont(arial);
    WinOText.setString("O Won!");
    WinOText.setCharacterSize(100);
    WinOText.setColor(sf::Color(239, 70, 128));
    
    sf::Text WinXText; // X Wins Text
    WinXText.setPosition(50, 460);
    WinXText.setFont(arial);
    WinXText.setString("X Won!");
    WinXText.setCharacterSize(100);
    WinXText.setColor(sf::Color(239, 70, 128));
    
    sf::RenderWindow window( sf::VideoMode( WIDTH, HIGHT ), "- Tic Tac Toe -" ); // Start Window
    
    sf::Texture buttonTexture; // Load Button Texture
    if (!buttonTexture.loadFromFile("Tic-Tac-Toe.png")) {
        std::cerr << "Button Texture Fail" << std::endl;
        return EXIT_FAILURE;
    }
    buttonTexture.setSmooth(true); // Turns Anti-Aliasing ON
    
    sf::RectangleShape backgroundRec; { // Creates Background With Border
        int borderSize = 8;
        backgroundRec.setPosition(borderSize, borderSize);
        backgroundRec.setSize(sf::Vector2f(WIDTH - 2*borderSize, HIGHT - 2*borderSize));
        backgroundRec.setOutlineThickness(borderSize);
    }
    backgroundRec.setFillColor(sf::Color::Black); // Background Color
    backgroundRec.setOutlineColor(sf::Color(239, 70, 128)); // Outline Color
    
    enum TileState { blank, O, X }; // Placer State enum
    enum GameState { PLAY, DRAW, WINX, WINO };
    GameState gs = PLAY;
    TileState state = X;
    
    TileState stateArray[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            stateArray[i][j] = blank;
        }
    }
    
    SpriteButton buttons[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            buttons[i][j].setTexture(buttonTexture);
            buttons[i][j].setPos(sf::Vector2f(40 + 140*i, 40 + 140*j));
            buttons[i][j].setSize(sf::Vector2f(128, 128));
            buttons[i][j].setTexturePos(sf::Vector2f(stateArray[i][j]*128, 0));
            buttons[i][j].setColor(sf::Color(239, 70, 128));
        }
    }
    bool WinPrimer[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            WinPrimer[i][j] = false;
        }
    }
    
    sf::Sprite stateIndicator;
    stateIndicator.setTexture(buttonTexture);
    stateIndicator.scale(1.2, 1.2);
    stateIndicator.setPosition(500, 60);
    stateIndicator.setTextureRect(sf::IntRect(0, 0, 128, 128));
    stateIndicator.setColor(sf::Color(239, 70, 128));
    
    
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
                        stateIndicator.setColor(sf::Color(239, 70, 128));
                        gs = PLAY;
                        state = X;
                        for(int i = 0; i < 3; i++) {
                            for(int j = 0; j < 3; j++) {
                                stateArray[i][j] = blank;
                                WinPrimer[i][j] = false;
                            }
                        }
                        for(int i = 0; i < 3; i++) {
                            for(int j = 0; j < 3; j++) {
                                buttons[i][j].setTexturePos(sf::Vector2f(stateArray[i][j]*128, 0));
                            }
                        }
                        stateIndicator.setColor(sf::Color(239, 70, 128));
                    }
                    
                } break;
                case sf::Event::MouseButtonPressed: {
                    if (gs != PLAY) {
                        stateIndicator.setColor(sf::Color(239, 70, 128));
                        gs = PLAY;
                        state = X;
                        for(int i = 0; i < 3; i++) {
                            for(int j = 0; j < 3; j++) {
                                stateArray[i][j] = blank;
                                WinPrimer[i][j] = false;
                            }
                        }
                        for(int i = 0; i < 3; i++) {
                            for(int j = 0; j < 3; j++) {
                                buttons[i][j].setTexturePos(sf::Vector2f(stateArray[i][j]*128, 0));
                            }
                        }
                        break;
                    }
                    for(int i = 0; i < 3; i++) {
                        for(int j = 0; j < 3; j++) {
                            if (buttons[i][j].check(window) && gs == PLAY) {
                                if (stateArray[i][j] == blank) {
                                    stateArray[i][j] = state;
                                    if (state == O) {state = X;}
                                    else if (state == X) {state = O;}
                                }
                                buttons[i][j].release();
                            }
                        }
                    }
                    if (stateArray[0][0] == X) {
                        if (stateArray[1][0] == X) {
                            if (stateArray[2][0] == X) {
                                gs = WINX;
                                WinPrimer[0][0] = true;
                                WinPrimer[1][0] = true;
                                WinPrimer[2][0] = true;
                                goto CheckEND;
                                // |X,X,X|
                                // | , , |
                                // | , , |
                            }
                        }
                    }
                    if (stateArray[0][0] == X) {
                        if (stateArray[1][1] == X) {
                            if (stateArray[2][2] == X) {
                                gs = WINX;
                                WinPrimer[0][0] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // |X, , |
                                // | ,X, |
                                // | , ,X|
                            }
                        }
                    }
                    if (stateArray[0][0] == X) {
                        if (stateArray[0][1] == X) {
                            if (stateArray[0][2] == X) {
                                gs = WINX;
                                WinPrimer[0][0] = true;
                                WinPrimer[0][1] = true;
                                WinPrimer[0][2] = true;
                                goto CheckEND;
                                // |X, , |
                                // |X, , |
                                // |X, , |
                            }
                        }
                    }
                    if (stateArray[0][1] == X) {
                        if (stateArray[1][1] == X) {
                            if (stateArray[2][1] == X) {
                                gs = WINX;
                                WinPrimer[0][1] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][1] = true;
                                goto CheckEND;
                                // | , , |
                                // |X,X,X|
                                // | , , |
                            }
                        }
                    }
                    if (stateArray[0][2] == X) {
                        if (stateArray[1][2] == X) {
                            if (stateArray[2][2] == X) {
                                gs = WINX;
                                WinPrimer[0][2] = true;
                                WinPrimer[1][2] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // | , , |
                                // | , , |
                                // |X,X,X|
                            }
                        }
                    }
                    if (stateArray[0][2] == X) {
                        if (stateArray[1][1] == X) {
                            if (stateArray[2][0] == X) {
                                gs = WINX;
                                WinPrimer[0][2] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][0] = true;
                                goto CheckEND;
                                // | , ,X|
                                // | ,X, |
                                // |X, , |
                            }
                        }
                    }
                    if (stateArray[1][0] == X) {
                        if (stateArray[1][1] == X) {
                            if (stateArray[1][2] == X) {
                                gs = WINX;
                                WinPrimer[1][0] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[1][2] = true;
                                goto CheckEND;
                                // | ,X, |
                                // | ,X, |
                                // | ,X, |
                            }
                        }
                    }
                    if (stateArray[2][0] == X) {
                        if (stateArray[2][1] == X) {
                            if (stateArray[2][2] == X) {
                                gs = WINX;
                                WinPrimer[2][0] = true;
                                WinPrimer[2][1] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // | , ,X|
                                // | , ,X|
                                // | , ,X|
                            }
                        }
                    }
                    
                    if (stateArray[0][0] == O) {
                        if (stateArray[1][0] == O) {
                            if (stateArray[2][0] == O) {
                                gs = WINO;
                                WinPrimer[0][0] = true;
                                WinPrimer[1][0] = true;
                                WinPrimer[2][0] = true;
                                goto CheckEND;
                                // |o,o,o|
                                // | , , |
                                // | , , |
                            }
                        }
                    }
                    if (stateArray[0][0] == O) {
                        if (stateArray[1][1] == O) {
                            if (stateArray[2][2] == O) {
                                gs = WINO;
                                WinPrimer[0][0] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // |o, , |
                                // | ,o, |
                                // | , ,o|
                            }
                        }
                    }
                    if (stateArray[0][0] == O) {
                        if (stateArray[0][1] == O) {
                            if (stateArray[0][2] == O) {
                                gs = WINO;
                                WinPrimer[0][0] = true;
                                WinPrimer[0][1] = true;
                                WinPrimer[0][2] = true;
                                goto CheckEND;
                                // |o, , |
                                // |o, , |
                                // |o, , |
                            }
                        }
                    }
                    if (stateArray[0][1] == O) {
                        if (stateArray[1][1] == O) {
                            if (stateArray[2][1] == O) {
                                gs = WINO;
                                WinPrimer[0][1] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][1] = true;
                                goto CheckEND;
                                // | , , |
                                // |o,o,o|
                                // | , , |
                            }
                        }
                    }
                    if (stateArray[0][2] == O) {
                        if (stateArray[1][2] == O) {
                            if (stateArray[2][2] == O) {
                                gs = WINO;
                                WinPrimer[0][2] = true;
                                WinPrimer[1][2] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // | , , |
                                // | , , |
                                // |o,o,o|
                            }
                        }
                    }
                    if (stateArray[0][2] == O) {
                        if (stateArray[1][1] == O) {
                            if (stateArray[2][0] == O) {
                                gs = WINO;
                                WinPrimer[0][2] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[2][0] = true;
                                goto CheckEND;
                                // | , ,o|
                                // | ,o, |
                                // |o, , |
                            }
                        }
                    }
                    if (stateArray[1][0] == O) {
                        if (stateArray[1][1] == O) {
                            if (stateArray[1][2] == O) {
                                gs = WINO;
                                WinPrimer[1][0] = true;
                                WinPrimer[1][1] = true;
                                WinPrimer[1][2] = true;
                                goto CheckEND;
                                // | ,o, |
                                // | ,o, |
                                // | ,o, |
                            }
                        }
                    }
                    if (stateArray[2][0] == O) {
                        if (stateArray[2][1] == O) {
                            if (stateArray[2][2] == O) {
                                gs = WINO;
                                WinPrimer[2][0] = true;
                                WinPrimer[2][1] = true;
                                WinPrimer[2][2] = true;
                                goto CheckEND;
                                // | , ,o|
                                // | , ,o|
                                // | , ,o|
                            }
                        }
                    }
                    stateIndicator.setTextureRect(sf::IntRect(state*128, 0, 128, 128));
                    {
                        bool ced = true;
                        for(int i = 0; i < 3; i++) { // This checks if there is no blank items
                            for(int j = 0; j < 3; j++) {
                                if (stateArray[i][j] == blank) { ced = false; }
                            }
                        }
                        if (ced) {
                            gs = DRAW; // If there is no blank items this happens
                            stateIndicator.setTextureRect(sf::IntRect(0, 0, 128, 128));
                            stateIndicator.setColor(sf::Color::Red);
                        }
                        ced = true;
                    }
                CheckEND:
                    for(int i = 0; i < 3; i++) {
                        for(int j = 0; j < 3; j++) {
                            buttons[i][j].setTexturePos(sf::Vector2f(stateArray[i][j]*128, 0));
                        }
                    }
                    break;
                }
            }
            
        }
        
        
        window.clear(sf::Color::Black);
        window.draw(backgroundRec);
        if(gs == WINO) {
            window.draw(WinOText);
            state = blank;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    buttons[i][j].setColor(sf::Color::Red);
                }
            }
        }
        if(gs == WINX) {
            window.draw(WinXText);
            state = blank;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    buttons[i][j].setColor(sf::Color::Magenta);
                }
            }
        }
        if(gs == WINO || WINX) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if (WinPrimer[i][j] == true) {
                        buttons[i][j].setColor(sf::Color::Green);
                    }
                }
            }
        };
        if(gs == PLAY) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    buttons[i][j].setColor(sf::Color(239, 70, 128));
                    stateIndicator.setTextureRect(sf::IntRect(state*128, 0, 128, 128));
                }
            }
        }
        if(gs == DRAW) {
            window.draw(FailText);
        }
        window.draw(stateIndicator);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                window.draw(*buttons[i][j].getSprite());
            }
        }
        window.display();
    }
    return 0;
}

