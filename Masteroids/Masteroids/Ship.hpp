//
//  Ship.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 5/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Point.hpp"

class Ship {
private:
    Point location;
    double angle;
    double angleM;
    double moment[2];
    Point vec[17];
    Point tipVec;
    int state;
    int thrustCount;
    int ammo;
public:
    Ship();
    MoPoint bullet[5];
    void setLocation(int i, double j);
    void setLocation(double i, double j);
    double getLocation(int i);
    void setMoment(int i, float j);
    void setMoment(float i, float j);
    double getMoment(int i);
    double* getMoment();
    void setAngle(double i);
    double getAngle();
    void setAngleM(double i);
    double getAngleM();
    void setState(int i);
    int getState();
    void renderShip( SDL_Renderer* &gRenderer );
    void initialize();
    void iterate();
    void addPoint( double x, double y );
    void rotatePoint(double v1, double v2, double &out1, double &out2, double angle);
    void thrust(double thr);
    void shoot();
    
};

#endif /* Ship_hpp */
