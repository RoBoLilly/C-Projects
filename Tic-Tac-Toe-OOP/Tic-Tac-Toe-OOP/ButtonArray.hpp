//
//  ButtonArray.hpp
//  Tic-Tac-Toe-OOP
//
//  Created by Lilly Fiorino on 10/1/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef ButtonArray_hpp
#define ButtonArray_hpp

#include <stdio.h>
#include "SpriteButton.hpp"

class ButtonArray {
private:
    SpriteButton buttons[3][3];
    sf::Texture buttonTexture;
public:
    ButtonArray(std::string path);
    SpriteButton getButton(int i, int j);
    sf::Texture* getTexture();
};

#endif /* ButtonArray_hpp */
