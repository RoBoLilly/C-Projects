//
//  Ship.cpp
//  Masteroids
//
//  Created blocation.Y Lilllocation.Y Fiorino on 5/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Ship.hpp"
#include "Screen_Size.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include "Point.hpp"

Ship::Ship(){
    angleM = 0;
    angle = 0;
    state = -1;
    thrustCount = 0;
    moment[0] = 0;
    moment[1] = 0;
    ammo = 5;
    vec[0].setPoint(20, 20);
    vec[1].setPoint(10, 0);
    vec[2].setPoint(30, -5);
    vec[3].setPoint(20,-20);
    vec[4].setPoint(20,-10);
    vec[5].setPoint(10,-10);
    vec[6].setPoint(-10,-20);
    vec[7].setPoint(-10,-10);
    vec[8].setPoint(-20,-10);
    vec[9].setPoint(-10, 10);
    vec[10].setPoint(-10, 20);
    vec[11].setPoint(-20, 20);
    vec[12].setPoint(-5, 30);
    vec[13].setPoint(0, 10);
    
    vec[14].setPoint(0, -30); // Flames
    vec[15].setPoint(-30,-30);
    vec[16].setPoint(-30, 0);
    
    for(int i=0; i<ammo; i++){ bullet[i].setPoint(tipVec); }
}

// Location
void Ship::setLocation(int i, double j){
    if(i==0){ location.X = j; }
    if(i==0){ location.Y = j; }
}
void Ship::setLocation(double i, double j){
    location.X = i;
    location.Y = j;
}
double Ship::getLocation(int i){
    if(i==0){ return location.X; }
    if(i==1){ return location.Y; }
    return 0;
}

// Moment
void Ship::setMoment(int i, float j){
    moment[i] = j;
}
void Ship::setMoment(float i, float j){
    moment[0] = i;
    moment[1] = j;
}
double Ship::getMoment(int i){
    return moment[i];
}
double* Ship::getMoment(){
    static double out[2];
    out[0] = moment[0];
    out[1] = moment[1];
    return out;
}

// Angle
void Ship::setAngle(double i){
    angle = i;
}
double Ship::getAngle(){
    return angle;
}

void Ship::setAngleM(double i){
    angleM = i;
}
double Ship::getAngleM(){
    return angleM;
}

// State
void Ship::setState(int i){
    state = i;
}
int Ship::getState(){
    return state;
}
void Ship::renderShip(SDL_Renderer* &gRenderer)
{
    Point temp[17];
    for(int i=0;i<17;i++){
        temp[i].setPoint(vec[i].rotatePoint(angle));
    }
    tipVec = temp[0];
    
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF); // Stipes
    SDL_RenderDrawLine(gRenderer, location.X + temp[1].X, location.Y + temp[1].Y, location.X + temp[6].X, location.Y + temp[6].Y);
    SDL_RenderDrawLine(gRenderer, location.X + temp[8].X, location.Y + temp[8].Y, location.X + temp[13].X, location.Y + temp[13].Y);
    
    if(thrustCount != 0){
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF); // Draw Flames
        SDL_RenderDrawLine(gRenderer, location.X + temp[14].X, location.Y + temp[14].Y, location.X + temp[3].X, location.Y + temp[3].Y);
        SDL_RenderDrawLine(gRenderer, location.X + temp[14].X, location.Y + temp[14].Y, location.X + temp[5].X, location.Y + temp[5].Y);
        SDL_RenderDrawLine(gRenderer, location.X + temp[15].X, location.Y + temp[15].Y, location.X + temp[6].X, location.Y + temp[6].Y);
        SDL_RenderDrawLine(gRenderer, location.X + temp[15].X, location.Y + temp[15].Y, location.X + temp[8].X, location.Y + temp[8].Y);
        SDL_RenderDrawLine(gRenderer, location.X + temp[16].X, location.Y + temp[16].Y, location.X + temp[9].X, location.Y + temp[9].Y);
        SDL_RenderDrawLine(gRenderer, location.X + temp[16].X, location.Y + temp[16].Y, location.X + temp[11].X, location.Y + temp[11].Y);
        thrustCount -= 1;
    }else{thrustCount = 0;}
    
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); // Draw Body
    for(int i=0; i<13; i++){
        SDL_RenderDrawLine(gRenderer, location.X + temp[i].X, location.Y + temp[i].Y, location.X + temp[i+1].X, location.Y + temp[i+1].Y);
    }
    SDL_RenderDrawLine(gRenderer, location.X + temp[13].X, location.Y + temp[13].Y, location.X + temp[0].X, location.Y + temp[0].Y);
    
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); // Set Color Blue
    
    for(int i=0; i<ammo; i++){
        SDL_RenderDrawPoint(gRenderer, bullet[i].X, bullet[i].Y);
    }
}
void Ship::iterate(){
    
    location.X = location.X + moment[0];
    location.Y = location.Y + moment[1];
    
    for(int i=0; i<ammo; i++)
    {
        if(bullet[i].getState() == 0){
            bullet[i].setPoint(tipVec.X + location.X, tipVec.Y + location.Y);
        }else{
            bullet[i].iterate();
        }
    }
    
    if (angle > 3.1415*2){angle = 0;}

    if(location.X > SCREEN_WIDTH){ location.X = 0; }
    if(location.Y > SCREEN_HEIGHT){ location.Y = 0; }
    if(location.X < 0){ location.X = SCREEN_WIDTH; }
    if(location.Y < 0){ location.Y = SCREEN_HEIGHT; }
    
    angle += angleM;
    if(angleM < 0.001 && angleM > -0.001){
        angleM = 0;
    }else{
        if(angleM > 0){angleM = angleM - 0.0001;}
        if(angleM < 0){angleM = angleM + 0.0001;}
    }
    
}

void Ship::rotatePoint(double v1, double v2, double &out1, double &out2, double angle){
    out1 = ( cos(angle) * v1 ) - ( sin(angle) * v2);
    out2 = ( sin(angle) * v1 ) + ( cos(angle) * v2);
}

void Ship::thrust(double thr){
    thrustCount = 30;
    double ves0;
    double ves1;
    rotatePoint(thr, thr, ves0, ves1, angle);
    moment[0] = moment[0] + ves0;
    moment[1] = moment[1] + ves1;
}
void Ship::shoot(){
    for(int i=0; i<ammo; i++){
        if(bullet[i].getState() == 0)
        {
            bullet[i].setState(1);
            rotatePoint(0.3, 0.3, bullet[i].XMoment, bullet[i].YMoment, angle);
            break;
        }
    }
}


//    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//    SDL_RenderDrawLine( gRenderer, location.X - 20, location.Y - 20, location.X + 20, location.Y - 20 );
//    SDL_RenderDrawLine( gRenderer, location.X + 20, location.Y - 20, location.X + 20, location.Y - 40 );
//    SDL_RenderDrawLine( gRenderer, location.X + 20, location.Y - 40, location.X + 60, location.Y );
//    SDL_RenderDrawLine( gRenderer, location.X + 60, location.Y, location.X + 20, location.Y );
//    SDL_RenderDrawLine( gRenderer, location.X + 20, location.Y, location.X + 20, location.Y + 20 );
//    SDL_RenderDrawLine( gRenderer, location.X + 20, location.Y + 20, location.X,   location.Y + 20 );
//    SDL_RenderDrawLine( gRenderer, location.X, location.Y + 20, location.X,   location.Y + 60 );
//    SDL_RenderDrawLine( gRenderer, location.X, location.Y + 60, location.X - 40, location.Y + 20 );
//    SDL_RenderDrawLine( gRenderer, location.X - 40, location.Y + 20, location.X - 20, location.Y + 20 );
//    SDL_RenderDrawLine( gRenderer, location.X - 20, location.Y + 20, location.X - 20, location.Y - 20 );
//    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//    SDL_RenderDrawLine( gRenderer, location.X - 20, location.Y + 40, location.X, location.Y + 40 );
//    SDL_RenderDrawLine( gRenderer, location.X + 40, location.Y - 20, location.X + 40, location.Y );
//    SDL_RenderDrawLine( gRenderer, location.X, location.Y + 20, location.X + 20, location.Y );


