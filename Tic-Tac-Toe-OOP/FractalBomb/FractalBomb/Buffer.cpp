//
//  Buffer.cpp
//  FractalBomb
//
//  Created by Lilly Fiorino on 10/3/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Buffer.hpp"
#include <SFML/Graphics.hpp>

Buffer::Buffer(int WIDTH, int HIGHT)
{
    w = WIDTH; h = HIGHT;
    buffer.resize(w);
    for (int i = 0; i < w; i++) {
        buffer[i].resize(h);
    }
}

sf::Color Buffer::get(int x, int y) {
    return buffer[x][y];
}

void Buffer::set(int x, int y, sf::Color color) {
    buffer[x][y] = color;
}
