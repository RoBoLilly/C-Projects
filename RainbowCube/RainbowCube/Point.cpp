//
//  Point.cpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "SDL_Init_Data.hpp"
#include "Point.hpp"
#include <math.h>

Point::Point(double x, double y){
    X = x;
    Y = y;
    R = 0;
    state = 0;
}
Point::Point(){
    X = 0;
    Y = 0;
    R = 0;
    state = 0;
}

void Point::setState(int i){
    state = i;
}
int Point::getState(){
    return state;
}

Point Point::rotatePoint(double angle){
    Point out;
    out.X = ( cos(angle) * X ) - ( sin(angle) * Y);
    out.Y = ( sin(angle) * X ) + ( cos(angle) * Y);
    return out;
}

Point Point::rotatePointAround(Point orign, double angle){
    Point out;
    out.X = cos(angle) * (X-orign.X) - sin(angle) * (Y-orign.Y) + orign.X;
    out.Y = sin(angle) * (X-orign.X) + cos(angle) * (Y-orign.Y) + orign.Y;
    return out;
}

void Point::setPoint(Point pnt){
    X = pnt.X;
    Y = pnt.Y;
}
void Point::setPoint(double x, double y){
    X = x;
    Y = y;
}
Point Point::midPoint(Point p1, Point p2){
    Point out;
    out.X = (p2.X + p1.X)/2;
    out.Y = (p2.Y + p1.Y)/2;
    return out;
}
void Point::scaleLine(Point i, Point &j, double scaler) // extends from i to j.
{
    j.X = j.X - i.X;
    j.Y = j.Y - i.Y;
    j.X = j.X * scaler;
    j.Y = j.Y * scaler;
    j.X = j.X + i.X;
    j.Y = j.Y + i.Y;
}

Rectangle::Rectangle(double x, double y, double w, double h){
    location.X = x;
    location.Y = y;
    vec[1].X = w;
    vec[2].X = w;
    vec[2].Y = h;
    vec[3].Y = h;
    PoR.X = w/2;
    PoR.Y = h/2;
    
}

void Rectangle::init(double x, double y, double w, double h){
    location.X = x;
    location.Y = y;
    vec[1].X = w;
    vec[2].X = w;
    vec[2].Y = h;
    vec[3].Y = h;
    PoR.X = w/2;
    PoR.Y = h/2;
}

void Rectangle::rotate(double angle){
    for(int i=0;i<4;i++)
    {
        vec[i].setPoint(vec[i].rotatePointAround(PoR, angle));
    }
}

void Rectangle::rotateAround(Point origin, double angle){
    for(int i=0;i<4;i++)
    {
        vec[i].setPoint(vec[i].rotatePointAround(origin, angle));
    }
}

void Rectangle::render(SDL_Renderer* &gRenderer){
    for(int i=0;i<3;i++)
    {
        SDL_RenderDrawLine(gRenderer, location.X + vec[i].X, location.Y + vec[i].Y, location.X + vec[i+1].X, location.Y + vec[i+1].Y);
    }
    SDL_RenderDrawLine(gRenderer, location.X + vec[3].X, location.Y + vec[3].Y, location.X + vec[0].X, location.Y + vec[0].Y);
}

MoPoint::MoPoint(){
    X = 0;
    Y = 0;
    XMoment = 0;
    YMoment = 0;
}
    
MoPoint::MoPoint(double x, double y, double xM, double yM)
{
    X = x;
    Y = y;
    XMoment = xM;
    YMoment = yM;
}
void MoPoint::iterate(){
    X = X + XMoment;
    Y = Y + YMoment;
    if(X > SCREEN_WIDTH){ X = 0; }
    if(Y > SCREEN_HEIGHT){ Y = 0; }
    if(X < 0){ X = SCREEN_WIDTH; }
    if(Y < 0){ Y = SCREEN_HEIGHT; }
}






