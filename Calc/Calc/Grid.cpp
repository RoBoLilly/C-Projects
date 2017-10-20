//
//  Grid.cpp
//  Calc
//
//  Created by Lilly Fiorino on 8/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include "Grid.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

Grid::Grid( sf::RenderWindow &Window ) {
    window = &Window;
    sf::Color color = sf::Color(255, 255, 0, 128);
    w = window->getSize().x;
    h = window->getSize().y;
    clear();
    for (int i = 0; i < w; i++) {
        if (i == w/2) {
            for (int j = 0; j < h; j++) {
                buffer[i][j] = color;
                if( j%10 < 1 ) {
                    for (int k = -3; k < 4; k++) {
                        buffer[i+k][j] = color;
                    }
                }
            }
        }
        for (int j = 0; j < h; j++) {
            if (j == h/2 ) {
                buffer[i][j] = color;
                if( i%10 < 1 ) {
                    for (int k = -3; k < 4; k++) {
                        buffer[i][j+k] = color;
                    }
                }
            }
        }
    }
}

void Grid::clear() {
    buffer.resize(w);
    for(int i = 0; i < w; i++) {
        buffer[i].resize(h);
    }
}

void Grid::draw() {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(1,1));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            rec.setPosition(i, j);
            rec.setFillColor(buffer[i][j]);
            window->draw(rec);
        }
    }
}

void Grid::setDrawColor(sf::Color color) {
    drawColor = color;
}

void Grid::plot(float (*f)(float)) {
}


void Grid::addPoint(int x, int y) {
    buffer[x][y] = drawColor;
}



