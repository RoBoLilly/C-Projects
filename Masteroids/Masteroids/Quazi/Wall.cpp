//
//  Wall.cpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/5/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Wall.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Screen_Size.hpp"

Wall::Wall(int w, double x, double y, double a, int sh, int sw){
    width = w;
    location[0] = x;
    location[1] = y;
    angle = a;
    SCREEN_HIGHT = sh;
    SCREEN_WIGTH = sw;
}
void Wall::setLocation(int i, double j){
    location[i] = j;
}
double Wall::getLocation(int i){
    return location[i];
}
void Wall::setAngle(double i){
    angle = i;
}
double Wall::getAngle(){
    return angle;
}
void Wall::renderWall(SDL_Renderer* &gRenderer){
    
    double vec[4];
    double temp[4];
    SDL_SetRenderDrawColor( gRenderer, 0x88, 0x40, 0x00, 0xFF );
    for(int a = 0;a < 20;a++)
    {
        vec[0] = location[0] + a;
        vec[1] = 0;
        vec[2] = location[0] + a;
        vec[3] = SCREEN_HIGHT;
        rotatePoint(vec[0], vec[1], temp[0], temp[1], angle);
        rotatePoint(vec[2], vec[3], temp[2], temp[3], angle);
        
        SDL_RenderDrawLine(gRenderer, temp[0], temp[1], temp[2], temp[3]);
    }
    //SDL_RenderDrawLine(gRenderer, 100, 100, 200, 200);
}

void Wall::rotatePoint(double v1, double v2, double &out1, double &out2, double angle)
{
//    px = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
//    py = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
    
    out1 = cos(angle) * (v1-location[0]) - sin(angle) * (v2-location[1]) + location[0];
    out2 = sin(angle) * (v1-location[0]) + cos(angle) * (v2-location[1]) + location[1];
}

bool Wall::isPointOver(double X, double Y)
{
    double vec0[2];
    double vec1[2];
    double vec2[2];
    double vec3[2];
    double temp0[2];
    double temp1[2];
    double temp2[2];
    double temp3[2];
    
    vec0[0] = location[0];
    vec0[1] = 0;
    vec1[0] = location[0] + 20;
    vec1[1] = 0;
    vec2[0] = location[0] + 20;
    vec2[1] = SCREEN_HIGHT;
    vec3[0] = location[0];
    vec3[1] = SCREEN_HIGHT;
    rotatePoint(vec0[0], vec0[1], temp0[0], temp0[1], angle);
    rotatePoint(vec1[0], vec1[1], temp1[0], temp1[1], angle);
    rotatePoint(vec2[0], vec2[1], temp2[0], temp2[1], angle);
    rotatePoint(vec3[0], vec3[1], temp3[0], temp3[1], angle);
    
    //double quazi = (temp2[0] - temp1[0]) * (Y - temp1[1]) - (temp2[1] - temp1[1]) * (X - temp0[0]);
    
    //printf("catts: %f\n" , quazi);
//    SDL_RenderDrawLine(gRenderer, temp0[0], temp0[1], temp1[0], temp1[1]);
//    SDL_RenderDrawLine(gRenderer, temp1[0], temp1[1], temp2[0], temp2[1]);
//    SDL_RenderDrawLine(gRenderer, temp2[0], temp2[1], temp3[0], temp3[1]);
//    SDL_RenderDrawLine(gRenderer, temp3[0], temp3[1], temp0[0], temp0[1]);
    
    if((temp1[0] - temp0[0]) * (Y - temp0[1]) - (temp1[1] - temp0[1]) * (X - temp0[0]) > 0){
        if((temp2[0] - temp1[0]) * (Y - temp1[1]) - (temp2[1] - temp1[1]) * (X - temp1[0]) > 0){
            if((temp3[0] - temp2[0]) * (Y - temp2[1]) - (temp3[1] - temp2[1]) * (X - temp2[0]) > 0){
                if((temp0[0] - temp3[0]) * (Y - temp3[1]) - (temp0[1] - temp3[1]) * (X - temp3[0]) > 0){
                    return true;
                }
            }
        }
    }

    return false;
}





