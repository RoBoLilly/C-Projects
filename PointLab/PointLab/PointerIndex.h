//
//  PointerIndex.h
//  PointLab
//
//  Created by Lilly Fiorino on 10/18/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef PointerIndex_h
#define PointerIndex_h

#include <SFML/Graphics.hpp>
#include "LinkedList.hpp"

struct PointerIndex {
    sf::Texture* particalTexture;
    sf::RenderWindow* window;
    LinkedList<Partical>* particalList;
};

#endif /* PointerIndex_h */
