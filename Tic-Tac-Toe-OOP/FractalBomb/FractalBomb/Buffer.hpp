//
//  Buffer.hpp
//  FractalBomb
//
//  Created by Lilly Fiorino on 10/3/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

class Buffer {
private:
    int w, h;
    std::vector<std::vector<sf::Color>> buffer;
public:
    Buffer(int WIDTH, int HIGHT);
    sf::Color get(int x, int y);
    void set(int x, int y, sf::Color color);
};

#endif /* Buffer_hpp */
