//
//  Text.h
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/22/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Text_h // TRUE
#define Text_h // FALSE

#include <iostream>
    sf::Font font;
    sf::Font RadixFont;
    if (!font.loadFromFile("Arial.ttf"))
    {
    std::cerr<<"/// - FONT ERROR - ///"<<std::endl;
    std::cin.get();
    }
    if (!RadixFont.loadFromFile("Painter.ttf"))
    {
        std::cerr<<"/// - FONT ERROR - ///"<<std::endl;
        std::cin.get();
    }
        
    
    sf::Text text;
    
    text.setPosition(100, 120);
    text.setFont(font);
    text.setString("Succsess!");
    text.setCharacterSize(100);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);
    
    sf::Text count;
    count.setFont(font);
    count.setCharacterSize(100);
    count.setColor(sf::Color::Red);
    count.setStyle(sf::Text::Bold);
    
    sf::Text PressY;
    //count.setPosition(900, 75);
    PressY.setFont(font);
    PressY.setString("Press Y To Sort!");
    PressY.setCharacterSize(100);
    PressY.setColor(sf::Color::Red);
    PressY.setStyle(sf::Text::Bold);
    
    sf::Text sorterSwaps;
    sorterSwaps.setPosition(750, 65);
    sorterSwaps.setFont(font);
    sorterSwaps.setString("0");
    sorterSwaps.setCharacterSize(35);
    //compares.setColor(sf::Color::Red);
    //compares.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    sf::Text totalSwaps;
    totalSwaps.setPosition(750, 20);
    totalSwaps.setFont(font);
    totalSwaps.setString("0");
    totalSwaps.setCharacterSize(35);
    totalSwaps.setColor(sf::Color(200,200,255));
    
    sf::Text RadixText;
    RadixText.setPosition(1080, 20);
    RadixText.setFont(RadixFont);
    RadixText.setString("Radix!");
    RadixText.setCharacterSize(100);
    RadixText.setColor(sf::Color::Red);
    RadixText.setStyle( sf::Text::Italic );
    
#endif /* Text_h */
