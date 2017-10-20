//
//  Grid.hpp
//  Calc
//
//  Created by Lilly Fiorino on 8/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
    int w, h;
    sf::RenderWindow* window;
    std::vector<std::vector<sf::Color>> buffer;
    sf::Color drawColor;
    
public:
    Grid( sf::RenderWindow &Window );
    void setDrawColor(sf::Color color);
    void plot( float (*f)(float) );
    void addPoint(int x, int y);
    void clear();
    void draw();
};


#endif /* Grid_hpp */
