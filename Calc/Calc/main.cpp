//
//  main.cpp
//  Calc
//
//  Created by Lilly Fiorino on 8/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include "MathFuncts.h"
#include "Grid.hpp"
#include "Function.hpp"

using namespace std;

struct dic {
    bool entered = false;
    int data;
} memo[128];

int fib(int n) {
    int f;
    if ( memo[n].entered == true ) { return memo[n].data; }
    if (n <= 2) { f = 1; return f; }
    else { f = fib(n-1) + fib(n-2); }
    memo[n].data = f;
    return f;
}
double sqr(double x) {
    return x*x;
}
double hight(double x) {
    return 0.1*(x*x) + 3*x;
};
double OilSlick(double x){
    return pi*sqr(70+6*x);
    //return PI*sqr(70+6*x);
}
double func(double x) {
    return OilSlick(x);
}

int main(int argc, const char * argv[])
{
    sf::Vector2f vec;
    const int width = 1080, hight = 720;
    sf::RenderWindow window( sf::VideoMode( width, hight ), "Calc" );
    window.setVerticalSyncEnabled(false);
    
    Grid grid(window);
    
    double x = 0;
    
    bool ha = true;
    while ( x <= 5 ) {
        cout << "X = " << x << endl;
        //cout << "X^2 = " << sqr(x) << endl;
        cout << "Derivative: " << derivative(func, x, 0.0001) << endl;
        //cout << "Second Derivative: " << secondDerivative(func, x) << endl;
        cout << "Y = " << func(x) << endl << endl;
        ha = false;
        x = x + 1;
    }
    
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
                case sf::Event::KeyPressed: {
                    if (e.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if (e.key.code == sf::Keyboard::Y) {
                    }
                } break;
            }
        }
        window.clear( sf::Color::Black );
        grid.draw();
        window.display();
        // Loop
    }
    window.close();
    return 0;
}
