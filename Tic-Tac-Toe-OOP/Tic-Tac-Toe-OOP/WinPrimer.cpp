//
//  WinPrimer.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "WinPrimer.hpp"

WinPrimer::WinPrimer() {};

void WinPrimer::set(int i, int j, bool state) {
    m_array[i][j] = state;
}
bool WinPrimer::get(int i, int j) {
    return m_array[i][j];
}
