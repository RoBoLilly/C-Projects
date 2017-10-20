//
//  DrawManager.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef DrawManager_hpp
#define DrawManager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

class DrawManager {
private:
    sf::RenderWindow* m_window;
    GameManager* GM;
public:
    DrawManager(sf::RenderWindow &window, GameManager &gameManager);
    void draw();
};

#endif /* DrawManager_hpp */
