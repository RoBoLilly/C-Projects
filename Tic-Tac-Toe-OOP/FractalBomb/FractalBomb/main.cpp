//
//  main.cpp
//  FractalBomb
//
//  Created by Lilly Fiorino on 10/2/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <pthread.h>
#include "Buffer.hpp"

const int WIDTH = 500*2;
const int HIGHT = 300*2;

void doFract(Buffer &buffer) {
    const double init_cRe = -0.7, init_cIm = 0.27; //initial julia constants
    double cRe, cIm;  //real and imaginary part of the constant c, determinate shape of the Julia Set
    double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
    double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
    sf::Color color; //the RGB color value for the pixel
    int maxIterations = 300; //after how much iterations the function should stop
    
    cRe = init_cRe;
    cIm = init_cIm;
    for(int y = 0; y < HIGHT; y++){
        for(int x = 0; x < WIDTH; x++) {
            //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
            newRe = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
            newIm = (y - HIGHT / 2) / (0.5 * zoom * HIGHT) + moveY;
            //i will represent the number of iterations
            unsigned int i;
            //start the iteration process
            for(i = 0; i < maxIterations; i++)
            {
                //remember value of previous iteration
                oldRe = newRe;
                oldIm = newIm;
                //the actual iteration, the real and imaginary part are calculated
                newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                newIm = 2 * oldRe * oldIm + cIm;
                //if the point is outside the circle with radius 2: stop
                if((newRe * newRe + newIm * newIm) > 4) break;
            }
            //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
            color = sf::Color(i % 256, 0, 255 * (i < maxIterations));
            //draw the pixel
            buffer.set(x, y, color);
            //window.draw(rec);
        }
    }
}

int main(int argc, const char * argv[])
{
    const double init_cRe = -0.7, init_cIm = 0.27; //initial julia constants
    bool shift = 0, alt = 0; // KeyPress States
    double cRe, cIm;  //real and imaginary part of the constant c, determinate shape of the Julia Set
    double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
    double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
    sf::Color color; //the RGB color value for the pixel
    int maxIterations = 300; //after how much iterations the function should stop
    
    cRe = init_cRe;
    cIm = init_cIm;
    
    int y = 0;
    
    bool JustStartAlready = true;
    
    sf::RenderWindow window( sf::VideoMode( WIDTH, HIGHT ), "- QuaZiNodE -" );
    
    Buffer buffer(WIDTH, HIGHT);
    
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(1,1));
    window.clear(sf::Color::Black);
    window.display();
    
//    pthread_t *tID;
//    int tErr;
    //tErr = pthread_create( tID , NULL, doFract, NULL);
    
    
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
                case sf::Event::KeyReleased:
                {
                    if(e.key.code == sf::Keyboard::LShift) {
                        shift = false;
                    }
                    if(e.key.code == sf::Keyboard::LAlt) {
                        alt = false;
                    }
                } break;
                case sf::Event::KeyPressed:
                {
                    if (e.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if(e.key.code == sf::Keyboard::LShift) {
                        shift = true;
                    }
                    if(e.key.code == sf::Keyboard::LAlt) {
                        alt = true;
                    }
                    if (e.key.code == sf::Keyboard::R) {
                        JustStartAlready = true;
                        cRe = init_cRe;
                        cIm = init_cIm;
                        zoom = 1;
                    }
                    if (e.key.code == sf::Keyboard::Up) {
                        if (shift) {
                            cRe = cRe + 0.01;
                        } else if (alt) {
                            cRe = cRe + 0.0005;
                        } else {
                            cRe = cRe + 0.0025;
                        }
                    }
                    if (e.key.code == sf::Keyboard::Down) {
                        if (shift) {
                            cRe = cRe - 0.01;
                        } else if (alt) {
                            cRe = cRe - 0.0005;
                        } else {
                            cRe = cRe - 0.0025;
                        }
                    }
                    if (e.key.code == sf::Keyboard::Left) {
                        if (shift) {
                            cIm = cIm + 0.04;
                        } else if (alt) {
                            cIm = cIm + 0.002;
                        } else {
                            cIm = cIm + 0.01;
                        }
                    }
                    if (e.key.code == sf::Keyboard::Right) {
                        if (shift) {
                            cIm = cIm - 0.04;
                        } else if (alt) {
                            cIm = cIm - 0.002;
                        } else {
                            cIm = cIm - 0.01;
                        }
                    }
                } break;
                case sf::Event::MouseButtonPressed: {
                } break;
            }
        }
        if(JustStartAlready) {
            doFract(buffer);
            for (int i = 0; i < WIDTH; i++) {
                for (int j = y%(HIGHT/16); j < HIGHT; j++) {
                    rec.setPosition(i, j);
                    rec.setFillColor(buffer.get(i, j));
                    window.draw(rec);
                }
            }
            //zoom = zoom + 0.01;
            window.display();
        }
    }
    return 0;
}
