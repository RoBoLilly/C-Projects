//
//  Partical.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/14/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Partical.hpp"
#include "Point2f.hpp"

Partical::Partical(){};
Partical::Partical(sf::Texture &texture, Point2f pos)
{
    position = pos;
    init(texture);
}
Partical::Partical(sf::Texture &texture, Point2f pos, Point2f moment)
{
    position = pos;
    momentumVector = moment;
    init(texture);
}
void Partical::init(sf::Texture &texture) {
    setTexture(texture);
    pointSprite.setTexture(*m_texture);
    pointSprite.setTextureRect(sf::IntRect(58, 58, 14, 14));
    pointSprite.setOrigin(7, 7);
    pointSprite.setPosition(position.x, position.y);
    repulsiveSprite.setTexture(*m_texture);
    repulsiveSprite.setTextureRect(sf::IntRect(128, 0, 128, 128));
    repulsiveSprite.setOrigin(64, 64);
    repulsiveSprite.setPosition(position.x, position.y);
    repulsiveSprite.setColor(sf::Color(255, 255, 0, 128));
    repulsiveSprite.setScale(repulsiveRadius/64, repulsiveRadius/64);
    attractiveSprite.setTexture(*m_texture);
    attractiveSprite.setTextureRect(sf::IntRect(128, 0, 128, 128));
    attractiveSprite.setOrigin(64, 64);
    attractiveSprite.setPosition(position.x, position.y);
    attractiveSprite.setColor(sf::Color(255, 0, 0, 82));
    attractiveSprite.setScale(attractiveRadius/64, attractiveRadius/64);
}

bool Partical::operator==(const Partical other) {
    if(this->ID == other.ID) {
        return true;
    }return false;
}
bool Partical::operator!=(const Partical other) {
    if(this->ID == other.ID) {
        return false;
    }return true;
}

Point2f Partical::getPos() {return position;}
Point2f Partical::getMomemt() {return momentumVector;}
float Partical::getRepulsiveR() {return repulsiveRadius;}
float Partical::getAttractiveR() {return attractiveRadius;}
void Partical::setPos(Point2f pos) {position = pos;}
void Partical::setMoment(Point2f moment) {momentumVector = moment;}
void Partical::flipMomentX() {momentumVector.x = momentumVector.x * -1;
    //pointSprite.setColor(sf::Color::Red);
}
void Partical::flipMomentY() {momentumVector.y = momentumVector.y * -1;
    //makeBenjamins();
}
void Partical::setRepulsiveR(float r){
    repulsiveRadius = r;
    repulsiveSprite.setScale(repulsiveRadius/64, repulsiveRadius/64);
}
void Partical::setAttractiveR(float r) {
    attractiveRadius = r;
    attractiveSprite.setScale(attractiveRadius/64, attractiveRadius/64);
}
void Partical::setTexture(sf::Texture &texture) {
    m_texture = &texture;
}
void Partical::iterate()
{
    position.x = position.x + momentumVector.x;
    position.y = position.y + momentumVector.y;
}
void Partical::draw(sf::RenderWindow &window)
{
    //repulsiveSprite.setPosition(position.x, position.y);
    //attractiveSprite.setPosition(position.x, position.y);
    pointSprite.setPosition(position.x, position.y);
    //window.draw(repulsiveSprite);
    //window.draw(attractiveSprite);
    window.draw(pointSprite);
}
void Partical::makeBenjamins()
{
    pointSprite.setColor(sf::Color::Blue);
}
