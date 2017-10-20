//
//  SpriteButton.hpp
//  Quazinode
//
//  Crea ted by Lilly Fiorino on 9/21/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef SpriteButton_hpp
#define SpriteButton_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class SpriteButton {
private:
    sf::Sprite* m_sprite;
    bool pressed = false;
    sf::Vector2f m_size;
    sf::Vector2f m_texturePos = {0, 0};
    sf::Vector2f m_pressedTexturePos = {0, 0};
public:
    SpriteButton(sf::Texture &texture);
    SpriteButton();
    ~SpriteButton();
    sf::Sprite* getSprite();
    void setTexture(sf::Texture &texture);
    bool isPressed();
    void setSize(sf::Vector2f size);
    void setPos(sf::Vector2f pos);
    void setTexturePos(sf::Vector2f pos);
    void setPressedTexturePos(sf::Vector2f pos);
    void setColor(sf::Color color);
    bool check(sf::RenderWindow &window);
    void release();
};

#endif /* SpriteButton_hpp */
