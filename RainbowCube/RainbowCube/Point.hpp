//
//  Point.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Point
{
public:
    Point();
    Point(double x, double y);
    double X;
    double Y;
    double R;
    double state;
    void setState(int i);
    int getState();
    Point rotatePoint(double angle);
    Point rotatePointAround(Point origin, double angle);
    void setPoint(Point pnt);
    void setPoint(double x, double y);
    Point midPoint(Point p1, Point p2);
    void scaleLine(Point i, Point &j, double scaler);
};

class Rectangle: public Point
{
public:
    Rectangle(double x=0, double y=0, double w=10, double h=10);
    void init(double x, double y, double w, double h);
    Point location;
    Point vec[4];
    Point PoR;
    void rotate(double angle);
    void rotateAround(Point origin, double angle);
    void render(SDL_Renderer* &gRenderer);
};

class MoPoint: public Point
{
public:
    MoPoint();
    MoPoint(double x, double y, double xM=0, double yM=0);
    double XMoment;
    double YMoment;
    void iterate();
};
#endif /* Point_hpp */


