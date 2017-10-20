//
//  Checker.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Checker_hpp
#define Checker_hpp

#include <stdio.h>
#include <vector>
#include "GameManager.hpp"

class Checker {
private:
    struct winPattern {
        int
        a1 = 0, a2 = 0,
        b1 = 0, b2 = 0,
        c1 = 0, c2 = 0;
    };
    std::vector<winPattern> p;
    GameManager* GM;
public:
    Checker(GameManager &gameManager);
    bool winCheck();
    bool catsCheck();
    bool buttonPress(sf::RenderWindow &window);
};

#endif /* Checker_hpp */
