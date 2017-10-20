//
//  StateArray.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef StateArray_hpp
#define StateArray_hpp

#include <stdio.h>

enum TileState { BLANK, O, X };

class StateArray {
private:
    TileState m_stateArray[3][3];
public:
    StateArray();
    void set(int i, int j, TileState state);
    TileState get(int i, int j);
};

#endif /* StateArray_hpp */
