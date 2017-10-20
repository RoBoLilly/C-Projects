//
//  Asteroid.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Astroroid_hpp
#define Astroroid_hpp

#include <stdio.h>
#include "Point.hpp"
#include <SDL2/SDL.h>

class Asteroid {
private:
    Point location;
    double moment[2];
    int size;
    int detail;
    Point vecs[16];
public:
    Asteroid();
    double radius;
    void setLocation(int i, double j);
    double getLocation(int i);
    void setMoment(int i, double j);
    double getMoment(int i);
    int getSize();
    void setSize(int i);
    void render(SDL_Renderer* gRenderer);
    void iterate();
    bool isInRadius(double X, double Y);
};

#endif /* Astroroid_hpp */
