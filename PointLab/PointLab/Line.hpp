//
//  Line.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/19/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Point2f.hpp"
#include "PointerIndex.h"

class Line {
private:
    Point2f m_point1;
    Point2f m_point2;
    sf::Color m_color;
    sf::RectangleShape line;
    PointerIndex* m_pI;
    float m_thickness = 1;
public:
    Line(PointerIndex &pI, Point2f point1, Point2f point2);
    void setPoints(Point2f point1, Point2f point2);
    void setP1(Point2f point);
    void setP2(Point2f point);
    Point2f getP1();
    Point2f getP2();
    Point2f getEnd();
    void setColor(sf::Color color);
    void setThickness(float thickness);
    float getThinkness();
    sf::Color getColor();
    void draw();
};

#endif /* Line_hpp */
