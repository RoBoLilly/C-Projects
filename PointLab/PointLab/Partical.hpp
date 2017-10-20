//
//  Partical.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/14/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Partical_hpp
#define Partical_hpp

#include <stdio.h>
#include "Point2f.hpp"
#include <SFML/Graphics.hpp>

class Partical {
private:
    sf::Texture* m_texture;
    sf::Sprite pointSprite;
    sf::Sprite repulsiveSprite;
    sf::Sprite attractiveSprite;
    Point2f position;
    Point2f momentumVector;
    float repulsiveRadius;
    float attractiveRadius;
public:
    int ID;
    Partical();
    Partical(sf::Texture &texture, Point2f pos);
    Partical(sf::Texture &texture, Point2f pos, Point2f moment);
    bool operator==(const Partical other);
    bool operator!=(const Partical other);
    Point2f getPos();
    Point2f getMomemt();
    float getRepulsiveR();
    float getAttractiveR();
    void setTexture(sf::Texture &texture);
    void setPos(Point2f pos);
    void setMoment(Point2f moment);
    void setRepulsiveR(float r);
    void setAttractiveR(float r);
    void flipMomentX();
    void flipMomentY();
    void init(sf::Texture &texture);
    void iterate();
    void draw(sf::RenderWindow &window);
    void makeBenjamins();
};

#endif /* Partical_hpp */
