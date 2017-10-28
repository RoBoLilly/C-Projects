//
//  PixelBuffer.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/19/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "PixelBuffer.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "PointerIndex.h"
#include "Point2f.hpp"

PixelBuffer::PixelBuffer(PointerIndex &pI){
    m_pI = &pI;
    size.x = m_pI->window->getSize().x;
    size.y = m_pI->window->getSize().y;
    m_buffer.resize(size.x);
    for(int i=0; i<size.x; i++){
        m_buffer[i].resize(size.y);
    }
}
void PixelBuffer::addPixel(int x, int y, char r, char g, char b, char a){
    m_buffer[x][y].load = true;
    m_buffer[x][y].r = r;
    m_buffer[x][y].g = g;
    m_buffer[x][y].b = b;
    m_buffer[x][y].a = a;
}
void PixelBuffer::addPixel(int x, int y, sf::Color color){
    m_buffer[x][y].load = true;
    m_buffer[x][y].r = color.r;
    m_buffer[x][y].g = color.g;
    m_buffer[x][y].b = color.b;
    m_buffer[x][y].a = color.a;
}
void PixelBuffer::addPixel(Point2f point, char r, char g, char b, char a){
    m_buffer[point.x][point.y].load = true;
    m_buffer[point.x][point.y].r = r;
    m_buffer[point.x][point.y].g = g;
    m_buffer[point.x][point.y].b = b;
    m_buffer[point.x][point.y].a = a;
}
void PixelBuffer::addPixel(Point2f point, sf::Color color){
    m_buffer[point.x][point.y].load = true;
    m_buffer[point.x][point.y].r = color.r;
    m_buffer[point.x][point.y].g = color.g;
    m_buffer[point.x][point.y].b = color.b;
    m_buffer[point.x][point.y].a = color.a;
}
void PixelBuffer::clear(){
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            m_buffer[i][j].load = false;
            m_buffer[i][j].r = 0;
            m_buffer[i][j].g = 0;
            m_buffer[i][j].b = 0;
            m_buffer[i][j].a = 0;
        }
    }
}

void PixelBuffer::draw(){
    sf::RectangleShape pix;
    pix.setSize(sf::Vector2f(1,1));
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            if(m_buffer[i][j].load){
                pix.setPosition(i,j);
                pix.setFillColor(sf::Color(m_buffer[i][j].r, m_buffer[i][j].g, m_buffer[i][j].b, m_buffer[i][j].a));
                m_pI->window->draw(pix);
            }
        }
    }
}
