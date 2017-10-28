//
//  Circle.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/18/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <SFML/Graphics.hpp>
#include "Point2f.hpp"
#include "PointerIndex.h"
#include <stdio.h>

class Circal {
private:
    PointerIndex* m_pI;
    sf::Sprite m_sprite;
    sf::Color m_color;
    Point2f m_position;
    float m_radius;
public:
    Circal();
    Circal(PointerIndex &pI, Point2f position, float radius);
    void setPointerIndex(PointerIndex &pI);
    void setPos(Point2f position);
    void setPos(float x, float y);
    void setRadius(float radius);
    void setColor(sf::Color color);
    sf::Color getColor();
    Point2f getPos();
    float getRadius();
    Point2f getPointAtAngle(float theta);
    Point2f getRotatedPoint(Point2f point, float theta);
    void draw();
};

#endif /* Circle_hpp */
