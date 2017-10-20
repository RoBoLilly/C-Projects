//
//  SpriteButton.cpp
//  Quazinode
//
//  Created by Lilly Fiorino on 9/21/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "SpriteButton.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

SpriteButton::SpriteButton(sf::Texture &texture)
{
    m_sprite = new sf::Sprite;
    m_sprite->setTexture(texture);
};

SpriteButton::SpriteButton()
{
    m_sprite = new sf::Sprite;
};

SpriteButton::~SpriteButton(){}

sf::Sprite* SpriteButton::getSprite() {
    return m_sprite;
}

void SpriteButton::setTexture(sf::Texture &texture) {
    m_sprite->setTexture(texture);
}

void SpriteButton::setSize(sf::Vector2f size) {
    m_size = size;
    m_sprite->setTextureRect(sf::IntRect(m_texturePos.x, m_texturePos.y, m_size.x, m_size.y));
}

void SpriteButton::setPos(sf::Vector2f pos) {
    m_sprite->setPosition(pos);
}

void SpriteButton::setTexturePos(sf::Vector2f pos) {
    m_texturePos = pos;
    m_sprite->setTextureRect(sf::IntRect(m_texturePos.x, m_texturePos.y, m_size.x, m_size.y));
}

void SpriteButton::setPressedTexturePos(sf::Vector2f pos) {
    m_pressedTexturePos = pos;
}

void SpriteButton::setColor(sf::Color color) {
    m_sprite->setColor(color);
}

bool SpriteButton::isPressed() { return pressed; }

bool SpriteButton::check(sf::RenderWindow &window) {
    bool succsess = false;
    if(sf::Mouse::getPosition(window).x > m_sprite->getPosition().x) {
        if(sf::Mouse::getPosition(window).x < m_sprite->getPosition().x + m_size.x) {
            if(sf::Mouse::getPosition(window).y > m_sprite->getPosition().y) {
                if(sf::Mouse::getPosition(window).y < m_sprite->getPosition().y + m_size.y) {
                    succsess = true;
                    m_sprite->setTextureRect(sf::IntRect(m_pressedTexturePos.x, m_pressedTexturePos.y, m_size.x, m_size.y));
                    //std::cout << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
                    pressed = true;
                }
            }
        }
    }
    return succsess;
}

void SpriteButton::release() {
    if(pressed)
        pressed = false;
        m_sprite->setTextureRect(sf::IntRect(m_texturePos.x, m_texturePos.y, m_size.x, m_size.y));
    
}
