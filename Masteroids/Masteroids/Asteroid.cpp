 //
//  Asteroid.cpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Screen_Size.hpp"
#include "Asteroid.hpp"
#include "Point.hpp"
#include <time.h>

double randMod(int mode){
    //srand((unsigned int)time(NULL));
    double num = 0;
    if(mode == 0)
    {
        num = rand()%100;
        if(num < 50){
            num = 1/(num - 50);
        }else{
            num = 1/num;
        }
        if(num > 0.06){num = 0.045;}
        if(num < -0.06){num = -0.045;}
    }
    if(mode == 1)
    {
        num = rand()%100;
        if(num < 50){
            num = num - 50;
        }else{
            num = num;
        }
    }
    if(mode == 2)
    {
        num = rand()&1000;
    }
    if(mode == 3)
    {
        num = rand()%100;
        if(num < 50){
            num = 1/(num - 50);
        }else{
            num = 1/num;
        }
    }
    if(mode == 4)
    {
        num = rand()%100;
    }
    return num;
}

Asteroid::Asteroid()
{
    location.X = randMod(2);
    location.Y = randMod(2);
    moment[0] = randMod(0);
    moment[1] = randMod(0);
    detail = 16;
    size = 2+rand()%3;
    for(int i=0;i<detail;i++){
        vecs[i].X = 1;
        vecs[i].Y = 0;
    }
    double angle = 0;
    double S;
    for(int i=0;i<detail;i++){
        vecs[i] = vecs[i].rotatePoint(angle);
        S = 10 * size + (randMod(4)/(30/size));
        vecs[i].X = vecs[i].X * S;
        vecs[i].Y = vecs[i].Y * S;
        angle = angle+(3.1415/8);
    }
    int temp = 0;
    
    for(int i=0;i<5;i++)
    {
        if(vecs[i].X>temp){
            temp=vecs[i].X;
        }
        if(vecs[i].Y>temp){
            temp=vecs[i].Y;
        }
    }
    radius = temp;
}

void Asteroid::setLocation(int i, double j)
{
    if(i == 0){ location.X = j; }
    if(i == 1){ location.Y = j; }
}

double Asteroid::getLocation(int i)
{
    if(i == 0){return location.X;}
    if(i == 1){return location.Y;}
    return 0;
}

void Asteroid::setMoment(int i, double j)
{
    moment[i] = j;
}
double Asteroid::getMoment(int i)
{
    return moment[i];
}
int Asteroid::getSize()
{
    return size;
}
void Asteroid::setSize(int i)
{
    size = i;
}

void Asteroid::render(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    for(int i=0;i<detail-1;i++){
        SDL_RenderDrawLine(gRenderer, location.X + vecs[i].X, location.Y + vecs[i].Y, location.X + vecs[i+1].X, location.Y + vecs[i+1].Y);
    }
    SDL_RenderDrawLine(gRenderer, location.X + vecs[detail-1].X, location.Y + vecs[detail-1].Y, location.X + vecs[0].X, location.Y + vecs[0].Y);
    iterate();
}

void Asteroid::iterate()
{
    location.X = location.X + moment[0];
    location.Y = location.Y + moment[1];
    
    if(location.X > SCREEN_WIDTH){ location.X = 0; }
    if(location.Y > SCREEN_HEIGHT){ location.Y = 0; }
    if(location.X < 0){ location.X = SCREEN_WIDTH; }
    if(location.Y < 0){ location.Y = SCREEN_HEIGHT; }
}

bool Asteroid::isInRadius(double X, double Y)
{
    double d = sqrt(((X-location.X)*(X-location.X))+((Y-location.Y)*(Y-location.Y)));
    if(d < radius){
        return true;
    }else{
        return false;
    }
}





