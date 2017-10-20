//
//  PixelBuffer.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/19/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef PixelBuffer_hpp
#define PixelBuffer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "PointerIndex.h"
#include "Point2f.hpp"

struct PixleData{
    bool load = false;
    char r=0, g=0, b=0, a=0;
};

class PixelBuffer {
private:
    std::vector<std::vector<PixleData>> m_buffer;
    Point2f size;
    PointerIndex* m_pI;
public:
    PixelBuffer(PointerIndex &pI);
    void addPixel(int x, int y, char r, char g, char b, char a);
    void addPixel(int x, int y, sf::Color color);
    void addPixel(Point2f point, char r, char g, char b, char a);
    void addPixel(Point2f point, sf::Color color);
    void clear();
    void draw();
};

#endif /* PixelBuffer_hpp */
