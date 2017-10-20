//
//  Line.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/19/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Line.hpp"
#include <iostream>
#include <math.h>

Line::Line(PointerIndex &pI, Point2f point1, Point2f point2){
    m_pI = &pI;
    setPoints(point1, point2);
}
void Line::setPoints(Point2f point1, Point2f point2){
    m_point1 = point1;
    m_point2 = point2;
    Point2f temp(m_point2.x-m_point1.x, m_point2.y-m_point1.y);
    float m = sqrt(temp.x*temp.x + temp.y*temp.y);
    temp = temp/m;
    line.setSize(sf::Vector2f(m, m_thickness));
    line.setOrigin(0, m_thickness/2);
    line.setRotation((-atan2(temp.x, temp.y)*(180/3.14159))+90);
    line.setPosition(point1.x, point1.y);
}
void Line::setP1(Point2f point){
    setPoints(point, m_point2);
}
void Line::setP2(Point2f point){
    setPoints(m_point1, point);
}
Point2f Line::getP1(){
    return m_point1;
}
Point2f Line::getP2(){
    return m_point2;
}
Point2f Line::getEnd(){
    Point2f temp(m_point2.x-m_point1.x, m_point2.y-m_point1.y);
    float r = -atan2(temp.x, temp.y)-(3.14159/2);
    return m_point1.getRotatedPointAroundOtherPoint(m_point2, r);
}
void Line::setColor(sf::Color color){
    m_color = color;
    line.setFillColor(m_color);
}
sf::Color Line::getColor(){
    return m_color;
}
void Line::setThickness(float thickness){
    m_thickness = thickness;
    float m = sqrt((m_point2.x-m_point1.x)*(m_point2.x-m_point1.x) + (m_point2.y-m_point1.y)*(m_point2.y-m_point1.y));
    line.setSize(sf::Vector2f(m, m_thickness));
    line.setOrigin(0, m_thickness/2);
}
float Line::getThinkness(){
    return m_thickness;
}
void Line::draw(){
    m_pI->window->draw(line);
}
