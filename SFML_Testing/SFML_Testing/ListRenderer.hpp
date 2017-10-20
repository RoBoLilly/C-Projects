//
//  ListRenderer.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/24/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef ListRenderer_hpp
#define ListRenderer_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "List.hpp"
#include "StateMachine.hpp"

class ListRenderer {
private:
    std::vector<sf::RectangleShape> rectList;
    sf::RenderWindow *window;
    StateMachine *s;
    int width;
    int hight;
    bool showIndexMark;
    int index;
    sf::Color listColor;
public:
    ListRenderer(sf::RenderWindow &Window, StateMachine &S);
    void render( List &List );
    void setRenderState(State S);
    void setIndex(int Index);
};

#endif /* ListRenderer_hpp */
