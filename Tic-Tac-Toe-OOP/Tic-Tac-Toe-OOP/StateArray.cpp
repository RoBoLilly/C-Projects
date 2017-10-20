//
//  StateArray.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "StateArray.hpp"

StateArray::StateArray()
{

};

void StateArray::set(int i, int j, TileState state) {
    m_stateArray[i][j] = state;
}
TileState StateArray::get(int i, int j) {
    return m_stateArray[i][j];
}
