//
//  Circle.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/18/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Circle.hpp"
#include "PointerIndex.h"
#include <iostream>
#include <math.h>

Circal::Circal(PointerIndex &pI, Point2f position, float radius){
    m_pI = &pI;
    m_position = position;
    m_radius = radius;
    m_sprite.setTexture(*m_pI->particalTexture);
    m_sprite.setTextureRect(sf::IntRect(128, 0, 128, 128));
    m_sprite.setOrigin(64, 64);
    m_sprite.setPosition(position.x, position.y);
    m_sprite.setScale(m_radius/64, m_radius/64);
}
void Circal::setPos(Point2f position){
    m_position = position;
}
void Circal::setPos(float x, float y){
    m_position.x = x;
    m_position.y = y;
}
void Circal::setRadius(float radius){
    m_radius = radius;
    m_sprite.setScale(m_radius/64, m_radius/64);
}
void Circal::setColor(sf::Color color){
    m_color = color;
    m_sprite.setColor(m_color);
}
sf::Color Circal::getColor(){
    return m_color;
}
Point2f Circal::getPos(){
    return m_position;
}
float Circal::getRadius(){
    return m_radius;
}
Point2f Circal::getPointAtAngle(float theta){
    Point2f temp;
    temp.x = (cos(theta) * (0-m_radius)) - (sin(theta) * (0)) + m_position.x;
    temp.y = (sin(theta) * (0-m_radius)) + (cos(theta) * (0)) + m_position.y;
    return temp;
}
Point2f Circal::getRotatedPoint(Point2f point, float theta){
    float m = sqrt((point.x-m_position.x)*(point.x-m_position.x) + (point.y-m_position.y)*(point.y-m_position.y));
    m = 1/(m_radius/m);
    Point2f temp;
    temp.x = (cos(theta) * (0-m_radius)) - (sin(theta) * (0));
    temp.y = (sin(theta) * (0-m_radius)) + (cos(theta) * (0));
    temp.x = temp.x * m;
    temp.y = temp.y * m;
    temp.x = temp.x + m_position.x;
    temp.y = temp.y + m_position.y;
    return temp;
}
void Circal::draw(){
    m_sprite.setPosition(m_position.x, m_position.y);
    m_pI->window->draw(m_sprite);
}







