//
//  Button.hpp
//  Quazinode
//
//  Created by Lilly Fiorino on 9/17/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>


class Button {
private:
    sf::RectangleShape* m_rect;
    sf::Color d_color = sf::Color::Red;
    sf::Color p_color = sf::Color::Blue;
    bool pressed = false;
public:
    Button();
    ~Button();
    sf::RectangleShape* getRect();
    bool isPressed();
    void setSize(sf::Vector2f size);
    void setPos(sf::Vector2f pos);
    void setColor(sf::Color color);
    void setPressedColor(sf::Color color);
    bool check(sf::RenderWindow &window);
    void release();
};

#endif /* Button_hpp */
