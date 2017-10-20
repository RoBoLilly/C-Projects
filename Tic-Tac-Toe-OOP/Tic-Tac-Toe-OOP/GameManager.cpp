//
//  GameManager.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "GameManager.hpp"
#include "Text.hpp"
#include "Background.hpp"
#include "ButtonArray.hpp"
#include "StateArray.hpp"
#include "WinPrimer.hpp"
#include "StateIndicator.hpp"
#include "GameStateMachine.hpp"

GameManager::GameManager(Text& text, Background& bg, ButtonArray& buttonArray, StateArray& stateArray, WinPrimer& winPrimer, StateIndicator& stateIndicator, GameStateMachine& gs, TileState& placeState)
{
    m_text = &text;
    m_bg = &bg;
    m_buttonArray = &buttonArray;
    m_stateArray = &stateArray;
    m_winPrimer = &winPrimer;
    m_stateIndicator = &stateIndicator;
    m_gs = &gs;
    m_placeState = &placeState;
}

void GameManager::reset()
{
    m_stateIndicator->get()->setColor(sf::Color(239, 70, 128));
    *m_gs = PLAY;
    *m_placeState = X;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m_stateArray->set(i, j, BLANK);
            m_winPrimer->set(i, j, false);
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m_buttonArray->getButton(i, j).setTexturePos(sf::Vector2f(m_stateArray->get(i, j)*128, 0));
        }
    }
    m_stateIndicator->get()->setColor(sf::Color(239, 70, 128));
}
void GameManager::updateButtonSprite() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m_buttonArray->getButton(i, j).setTexturePos(sf::Vector2f(m_stateArray->get(i, j)*128, 0));
        }
    }
}


Text* GameManager::text() { return m_text; }
Background* GameManager::bg() { return m_bg; }
ButtonArray* GameManager::buttonArray() { return m_buttonArray; }
StateArray* GameManager::stateArray() { return m_stateArray; }
WinPrimer* GameManager::winPrimer() { return m_winPrimer; }
StateIndicator* GameManager::stateIndicator() { return m_stateIndicator; }
GameStateMachine* GameManager::gs() { return m_gs; }
TileState* GameManager::placeState() { return m_placeState; }
