//
//  main.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include "Point2f.hpp"
#include "LinkedList.hpp"
#include "Field.hpp"
#include "PointerIndex.h"
#include "Circle.hpp"
#include "Line.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "PixelBuffer.hpp"

enum ProgramSetting { GRID, TESTING, TEACHING };

const float pi = 3.14159;

int main(int argc, const char * argv[]) {
    PointerIndex pI;
    sf::Texture particalTexture;
    particalTexture.setSmooth(true);
    particalTexture.loadFromFile("ParticalTexture.png");
    pI.particalTexture = &particalTexture;
    
    Point2f windowSize(1080, 720);
    sf::RenderWindow window( sf::VideoMode( windowSize.x, windowSize.y ), "- PointLab -" );
    pI.window = &window;
    
    PixelBuffer pixelBuffer(pI);
    
    const int cA = 255;
    Field field(windowSize);
    LinkedList ll;
    Partical root1(particalTexture, Point2f(1080/2, 720/2));
    Circal circal1(pI, root1.getPos(), 100);
    circal1.setColor(sf::Color(0,0,255,cA));
    Partical rider1(particalTexture, circal1.getPointAtAngle(0));
    Partical rider2(particalTexture, circal1.getPointAtAngle(pi/2));
    Partical rider3(particalTexture, circal1.getPointAtAngle(pi));
    Partical rider4(particalTexture, circal1.getPointAtAngle((pi/2)*3));
    Partical base1(particalTexture, Point2f(root1.getPos().x + 100,root1.getPos().y));
    Circal circal2(pI, base1.getPos(), 70);
    circal2.setColor(sf::Color(0,0,255,cA));
    Partical base2(particalTexture, circal2.getPointAtAngle(0));
    Circal circal3(pI, base2.getPos(), 70);
    circal3.setColor(sf::Color(0,0,255,cA));
    Partical base3(particalTexture, circal3.getPointAtAngle(0));
    Partical spot1(particalTexture, rider1.getPos().getPointinBetween(root1.getPos()));
    
    float theta = 0.0;
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
                    if (e.key.code == sf::Keyboard::K) {
                        for(Node* n = ll.head; n != nullptr; n = n->next){
                            field.addAttraction(n->data, ll);
                        }
                    }
                    if (e.key.code == sf::Keyboard::B) {
                        for(Node* n = ll.head; n != nullptr; n = n->next){
                            n->data.setAttractiveR(n->data.getAttractiveR() + 5);
                        }
                    }
                    if (e.key.code == sf::Keyboard::C) {
                        pixelBuffer.clear();
                    }
                    if (e.key.code == sf::Keyboard::R) {
                        for(Node* n = ll.head; n != nullptr; n = n->next){
                            n->data.setMoment(Point2f(1+rand()&100, 1+rand()&100));
                            n->data.setMoment(Point2f(10/n->data.getMomemt().x, 10/n->data.getMomemt().y));
                        }
                    }
                } break;
                case sf::Event::MouseButtonPressed: {
                } break;
            }
        }
        window.clear(sf::Color::Black);
        for(Node* n = ll.head; n != nullptr; n = n->next){
            n->data.draw(window);
            n->data.iterate();
            field.bounderyCheck(n->data);
        }
        circal1.draw();
        theta = theta + 0.01;

        base1.draw(window);
        base1.setPos(circal1.getRotatedPoint(base1.getPos(), (pi*2)-(theta*(1)))); // (1), (3)
        circal2.setPos(base1.getPos());
        circal2.draw();
        base2.setPos(circal2.getPointAtAngle(theta*(9/4))); // (9/4), (2)
        base2.draw(window);
        circal3.setPos(base2.getPos());
        circal3.draw();
        base3.setPos(circal3.getPointAtAngle(theta*(3))); // (3), (8.01)
        base3.draw(window);
        pixelBuffer.addPixel(base3.getPos(), sf::Color::Yellow);

        pixelBuffer.draw();
        window.display();
    }
    ll.cleanUp();
    return 0;
}

