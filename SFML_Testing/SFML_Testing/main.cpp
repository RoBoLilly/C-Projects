//
//  main.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/18/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "List.hpp"
#include "ListRenderer.hpp"
#include "StateMachine.hpp"
#include "Sorter.hpp"
#include "TotalSwaps.h"

using namespace std;

static inline std::string int2Str(int x);

int main(int argc, const char * argv[])
{
    Swaps swaps;
#include "Text.h"
    sf::RenderWindow window( sf::VideoMode( 1080*2, 720*2 ), "SFML Test" );
    window.setVerticalSyncEnabled(false);
    
    sf::Font arial;
    if (!arial.loadFromFile("Arial.ttf"))
    {
        std::cerr<<"/// - FONT ERROR - ///"<<std::endl;
        std::cin.get();
    }

    int LIST_SIZE = 256; // Flag - | -_-_- | - LIST_SIZE - |
    int LEVELS = 256;
    swaps.resetTotal();
    swaps.resetSwaps();
    
    List list(LIST_SIZE);
    StateMachine s(START);
    ListRenderer ListRend(window, s);
    list.fillRand(LEVELS);
    Sorter sorter(list, RADIX_SORT, swaps);
    
    while ( window.isOpen() ) // Main Loop - |
    {
        sf::Event e; // Event Manager - |
        while ( window.pollEvent(e) ) {
            switch (e.type) {
                default:
                    break;
                case sf::Event::Closed: {
                    window.close();
                } break;
                case sf::Event::KeyPressed:
                {
                    if (e.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if (e.key.code == sf::Keyboard::Period) {
                        window.setVerticalSyncEnabled(false);
                    }
                    if (e.key.code == sf::Keyboard::Comma) {
                        window.setVerticalSyncEnabled(true);
                    }
                    if (e.key.code == sf::Keyboard::R) {
                        sorter.setState(RADIX_SORT, list);
                    }
                    if (e.key.code == sf::Keyboard::Y) {
                        if (s.state == IDLE) {
                            s.state = START;
                            list.setSize(LIST_SIZE);
                            list.fillRand(LIST_SIZE);
                            sorter.resetTotalSwaps();
                        } else if (s.state == SORT){
                            if (sorter.getState() == BUBBLE_SORT) {
                                sorter.setState( TOP_SORT, list );
                                sorter.setList(list);
                            } else if (sorter.getState() == TOP_SORT) {
                                sorter.setState( BUBBLE_SORT, list );
                                sorter.setList(list);
                            } else if (sorter.getState() == RADIX_SORT) {
                                sorter.setState( BUBBLE_SORT, list );
                                sorter.setList(list);
                            }
                        }
                    }
                } break;
            }
        }
        
        ListRend.setIndex(sorter.getIndex());
        if (list.Size() == 0) { s.state = IDLE; }
        window.clear(sf::Color(0, 0, 153)); // - | -_-_- | - CLEAR WINDOW - |
        
        if ( s.state != IDLE ) {
            count.setString("Elements: " + int2Str(list.Size()));
            window.draw(count);
        }
        switch (s.state) {
            case IDLE : {
                window.draw(PressY);
                window.draw(totalSwaps);
                window.display();
            }break;
            case SORT : {
                if ( sorter.Sort() ) { s.state = SUCCSESS; }
                sf::RectangleShape stateButton(sf::Vector2f(40, 40));
                stateButton.setSize(sf::Vector2f(window.getSize().x, 10));
                if (sorter.getState() == BUBBLE_SORT) {
                    stateButton.setFillColor(sf::Color::Cyan);
                } else {
                    stateButton.setFillColor(sf::Color::Magenta);
                }
                if (sorter.getState() == RADIX_SORT) { window.draw(RadixText); }
                sorterSwaps.setString("Swaps: " + int2Str(sorter.getSwaps()));
                totalSwaps.setString("TotalSwaps: " + int2Str(sorter.getTotalSwaps()));
                window.draw(sorterSwaps);
                window.draw(totalSwaps);
                window.draw(stateButton);
                ListRend.render(list);
                window.display();
            }break;
            case SUCCSESS : {
                ListRend.render(list);
                window.draw(text);
                window.draw(totalSwaps);
                window.draw(sorterSwaps);
                window.display();
                sf::Time pauseTime = sf::seconds(0.2f);
                sf::sleep(pauseTime);
                s.state = START;
                sorter.setIndex(0);
                sorter.resetSwaps();
                list.setSize(list.Size()-1);
                list.fillRand(LEVELS);
            }break;
            case START : {
                ListRend.render(list);
                window.draw(totalSwaps);
                window.display();
                sf::Time pauseTime = sf::seconds(0.2f);
                sf::sleep(pauseTime);
                s.state = SORT;
            }break;
            default:break;
        }
        
//        sf::Time pauseTime = sf::seconds(0.2f);
//        sf::sleep(pauseTime);
        
    }
    return 0;
}

// Converts ints to strings
static inline std::string int2Str(int x)
{
    std::stringstream type;
    type << x;
    return type.str();
}











