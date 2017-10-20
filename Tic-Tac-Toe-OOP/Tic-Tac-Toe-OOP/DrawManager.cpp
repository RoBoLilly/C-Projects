//
//  DrawManager.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "DrawManager.hpp"

DrawManager::DrawManager(sf::RenderWindow &window, GameManager &gameManager) {
    m_window = &window;
    GM = &gameManager;
};

void DrawManager::draw()
{
    m_window->draw(GM->bg()->getBackground());
    if(GM->gs()->state == WINO) {
        m_window->draw(GM->text()->getWinO());
        *GM->placeState() = BLANK;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                GM->buttonArray()->getButton(i, j).setColor(sf::Color::Red);
            }
        }
    }
    if(GM->gs()->state == WINX) {
        m_window->draw(GM->text()->getWinX());
        *GM->placeState() = BLANK;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                GM->buttonArray()->getButton(i, j).setColor(sf::Color::Magenta);
            }
        }
    }
    if(GM->gs()->state == WINO || WINX) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if (GM->winPrimer()->get(i, j) == true) {
                    GM->buttonArray()->getButton(i, j).setColor(sf::Color::Green);
                }
            }
        }
    };
    if(GM->gs()->state == PLAY) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                GM->buttonArray()->getButton(i, j).setColor(sf::Color(239, 70, 128));
                GM->stateIndicator()->get()->setTextureRect(sf::IntRect(*GM->placeState()*128, 0, 128, 128));
            }
        }
    }
    if(GM->gs()->state == DRAW) {
        m_window->draw(GM->text()->getCats());
    }
    m_window->draw(*GM->stateIndicator()->get());
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m_window->draw(*GM->buttonArray()->getButton(i, j).getSprite());
        }
    }
}
