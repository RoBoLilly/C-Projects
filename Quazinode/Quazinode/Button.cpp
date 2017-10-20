//
//  Button.cpp
//  Quazinode
//
//  Created by Lilly Fiorino on 9/17/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Button::Button()
{
    sf::RectangleShape* rect = new sf::RectangleShape();
    m_rect = rect;
};

Button::~Button(){
    delete m_rect;
}

sf::RectangleShape* Button::getRect() {
    return m_rect;
}

void Button::setSize(sf::Vector2f size) {
    m_rect->setSize(size);
}

void Button::setPos(sf::Vector2f pos) {
    m_rect->setPosition(pos);
}

void Button::setColor(sf::Color color) {
    m_rect->setFillColor(color);
    this->d_color = color;
}

void Button::setPressedColor(sf::Color color) {
    this->p_color = color;
}

bool Button::isPressed() { return pressed; }

bool Button::check(sf::RenderWindow &window) {
    bool succsess = false;
    if(sf::Mouse::getPosition(window).x > m_rect->getPosition().x) {
        if(sf::Mouse::getPosition(window).x < m_rect->getPosition().x + m_rect->getSize().x) {
            if(sf::Mouse::getPosition(window).y > m_rect->getPosition().y) {
                if(sf::Mouse::getPosition(window).y < m_rect->getPosition().y + m_rect->getSize().y) {
                    succsess = true;
                    //std::cout << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
                    m_rect->setFillColor(p_color);
                    pressed = true;
                }
            }
        }
    }
    return succsess;
}

void Button::release() {
    if(pressed)
        pressed = false;
        m_rect->setFillColor(d_color);
}


