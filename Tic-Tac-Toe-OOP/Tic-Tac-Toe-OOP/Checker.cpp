//
//  Checker.cpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Checker.hpp"
#include "GameManager.hpp"

Checker::Checker(GameManager &gameManager)
{
    GM = &gameManager;
    p.resize(8);
    p[0].a1 = 0; p[0].a2 = 0;
    p[0].b1 = 1; p[0].b2 = 0;
    p[0].c1 = 2; p[0].c2 = 0;
    // |X,X,X|
    // | , , |
    // | , , |
    
    p[1].a1 = 0; p[1].a2 = 0;
    p[1].b1 = 1; p[1].b2 = 1;
    p[1].c1 = 2; p[1].c2 = 2;
    // |X, , |
    // | ,X, |
    // | , ,X|
    
    p[2].a1 = 0; p[2].a2 = 0;
    p[2].b1 = 0; p[2].b2 = 1;
    p[2].c1 = 0; p[2].c2 = 2;
    // |X, , |
    // |X, , |
    // |X, , |
    
    p[3].a1 = 0; p[3].a2 = 1;
    p[3].b1 = 1; p[3].b2 = 1;
    p[3].c1 = 2; p[3].c2 = 1;
    // | , , |
    // |X,X,X|
    // | , , |
    
    p[4].a1 = 0; p[4].a2 = 2;
    p[4].b1 = 1; p[4].b2 = 2;
    p[4].c1 = 2; p[4].c2 = 2;
    // | , , |
    // | , , |
    // |X,X,X|
    
    p[5].a1 = 2; p[5].a2 = 0;
    p[5].b1 = 1; p[5].b2 = 1;
    p[5].c1 = 0; p[5].c2 = 2;
    // | , ,X|
    // | ,X, |
    // |X, , |
    
    p[6].a1 = 1; p[6].a2 = 0;
    p[6].b1 = 1; p[6].b2 = 1;
    p[6].c1 = 1; p[6].c2 = 2;
    // | ,X, |
    // | ,X, |
    // | ,X, |
    
    p[7].a1 = 2; p[7].a2 = 0;
    p[7].b1 = 2; p[7].b2 = 1;
    p[7].c1 = 2; p[7].c2 = 2;
    // | , ,X|
    // | , ,X|
    // | , ,X|
}

bool Checker::winCheck()
{
    for(int i = 0; i < 8; i++) {
        if (GM->stateArray()->get(p[i].a1, p[i].a2) == X) {
            if (GM->stateArray()->get(p[i].b1, p[i].b2) == X) {
                if (GM->stateArray()->get(p[i].c1, p[i].c2) == X) {
                    *GM->gs() = WINX;
                    GM->winPrimer()->set(p[i].a1, p[i].a2, true);
                    GM->winPrimer()->set(p[i].b1, p[i].b2, true);
                    GM->winPrimer()->set(p[i].c1, p[i].c2, true);
                    return true;
                }
            }
        }
    }
    for(int i = 0; i < 8; i++) {
        if (GM->stateArray()->get(p[i].a1, p[i].a2) == O) {
            if (GM->stateArray()->get(p[i].b1, p[i].b2) == O) {
                if (GM->stateArray()->get(p[i].c1, p[i].c2) == O) {
                    *GM->gs() = WINO;
                    GM->winPrimer()->set(p[i].a1, p[i].a2, true);
                    GM->winPrimer()->set(p[i].b1, p[i].b2, true);
                    GM->winPrimer()->set(p[i].c1, p[i].c2, true);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Checker::catsCheck()
{
    for(int i = 0; i < 3; i++) { // This checks if there is no blank items
        for(int j = 0; j < 3; j++) {
            if (GM->stateArray()->get(i, j) == BLANK) { return true; }
        }
    }
    return false;
}

bool Checker::buttonPress(sf::RenderWindow &window)
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (GM->buttonArray()->getButton(i, j).check(window) && GM->gs()->state == PLAY) {
                if (GM->stateArray()->get(i, j) == BLANK) {
                    GM->stateArray()->set(i, j, *GM->placeState());
                    if (*GM->placeState() == O) {*GM->placeState() = X;}
                    else if (*GM->placeState() == X) {*GM->placeState() = O;}
                }
                GM->buttonArray()->getButton(i, j).release();
                
            }
        }
    }
    return true;
}


