//
//  Wall.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/5/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Screen_Size.hpp"

class Wall
{
private:
    int SCREEN_HIGHT;
    int SCREEN_WIGTH;
    int location[2];
    double angle;
    int width;
    void rotatePoint(double v1, double v2, double &out1, double &out2, double angle);
public:
    Wall(int w, double x, double y, double a, int sh, int sw);
    void setLocation(int i, double j);
    double getLocation(int i);
    void setAngle(double i);
    double getAngle();
    void renderWall(SDL_Renderer* &gRenderer);
    bool isPointOver(double x, double y);
};

#endif /* Wall_hpp */
