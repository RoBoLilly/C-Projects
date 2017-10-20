//
//  GameStateMachine.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef GameStateMachine_hpp
#define GameStateMachine_hpp

#include <stdio.h>

enum GameState { PLAY, DRAW, WINX, WINO };
class GameStateMachine {
public:
    GameStateMachine(GameState startState);
    GameState state;
};

#endif /* GameStateMachine_hpp */
