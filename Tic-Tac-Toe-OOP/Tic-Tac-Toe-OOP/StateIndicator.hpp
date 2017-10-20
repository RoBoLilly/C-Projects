//
//  StateIndicator.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef StateIndicator_hpp
#define StateIndicator_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class StateIndicator {
private:
    sf::Texture* m_texture;
    sf::Sprite stateIndicator;
public:
    StateIndicator(sf::Texture* texture);
    sf::Sprite* get();
};

#endif /* StateIndicator_hpp */
