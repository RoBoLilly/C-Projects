//
//  WinPrimer.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef WinPrimer_hpp
#define WinPrimer_hpp

#include <stdio.h>

class WinPrimer {
private:
    bool m_array[3][3];
public:
    WinPrimer();
    void set(int i, int j, bool state);
    bool get(int i, int j);
};

#endif /* WinPrimer_hpp */
