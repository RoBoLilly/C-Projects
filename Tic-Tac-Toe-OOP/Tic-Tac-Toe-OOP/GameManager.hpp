//
//  GameManager.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "Text.hpp"
#include "Background.hpp"
#include "ButtonArray.hpp"
#include "StateArray.hpp"
#include "WinPrimer.hpp"
#include "StateIndicator.hpp"
#include "GameStateMachine.hpp"

class GameManager {
private:
    Text* m_text;
    Background* m_bg;
    ButtonArray* m_buttonArray;
    StateArray* m_stateArray;
    WinPrimer* m_winPrimer;
    StateIndicator* m_stateIndicator;
    GameStateMachine* m_gs;
    TileState* m_placeState;
public:
    GameManager(Text& text, Background& bg, ButtonArray& buttonArray, StateArray& stateArray, WinPrimer& winPrimer, StateIndicator& stateIndicator, GameStateMachine& gs, TileState& placeState);
    void reset();
    void updateButtonSprite();
    Text* text();
    Background* bg();
    ButtonArray* buttonArray();
    StateArray* stateArray();
    WinPrimer* winPrimer();
    StateIndicator* stateIndicator();
    GameStateMachine* gs();
    TileState* placeState();
};

#endif /* GameManager_hpp */
