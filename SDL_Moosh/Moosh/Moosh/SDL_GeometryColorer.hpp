//
//  SDL_GeometryColorer.hpp
//  Moosh
//
//  Created by Lilly Fiorino on 5/27/17.
//  Copyright © 2017 SDL_Moosh. All rights reserved.
//

#ifndef SDL_GeometryColorer_hpp
#define SDL_GeometryColorer_hpp

#include <stdio.h>
#include <SDL2_image/SDL_image.h>

void SDLGC_rainbowColor(SDL_Renderer* &gRenderer, int  i);

class SDLGC
{
private:
    int red = 0;
    int green = 0;
    int blue = 0;
public:
    void setColors(int r, int g, int b);
    int getColor(int i);
    void fadeRed(SDL_Renderer* &gRenderer, int i);
};

void SDLGC::setColors(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

int SDLGC::getColor(int i)
{
    switch(i){
        case 0:
            return red;
            break;
        case 1:
            return green;
            break;
        case 2:
            return blue;
        default:
            return 0;
    }
}

void SDLGC::fadeRed(SDL_Renderer* &gRenderer, int i)
{
    if(red < 255){
        red += i;
    }
    if(green > 0){
        green -= i;
    }
    if(blue > 0){
        blue -= i;
    }
    SDL_SetRenderDrawColor( gRenderer, red, green, blue, 255 );
}

int rainRed = 255;
int rainGreen = 0;
int rainBlue = 0;
int rainMode = 0;

void SDLGC_rainbowColor(SDL_Renderer* &gRenderer, int  i)
{
    switch (rainMode) {
        case 0:
            rainGreen += i;
            if(rainGreen >= 255){rainMode = 1;}
            break;
        case 1:
            rainRed -= i;
            if(rainRed <= 0){rainMode = 2;}
            break;
        case 2:
            rainBlue += i;
            if(rainBlue >= 255){rainMode = 3;}
            break;
        case 3:
            rainGreen -= i;
            if(rainGreen <= 0){rainMode = 4;}
            break;
        case 4:
            rainRed += i;
            if(rainRed >= 255){rainMode = 5;}
            break;
        case 5:
            rainBlue -= i;
            if(rainBlue <= 0){rainMode = 0;}
            break;
        default:
            rainMode = 0;
            break;
    }
    SDL_SetRenderDrawColor( gRenderer, rainRed, rainGreen, rainBlue, 255 );
}

#endif /* SDL_GeometryColorer_hpp */
