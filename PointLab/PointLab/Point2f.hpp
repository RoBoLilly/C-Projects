//
//  Point2f.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Point2f_hpp
#define Point2f_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

class Point2f {
public:
    float x, y;
    Point2f() {
        x = 0;
        y = 0;
    }
    Point2f(float X, float Y) {
        x = X;
        y = Y;
    }
    void print() { std::cout << "(" << x << ", " << y << ")"; }
    void printl() { print(); std::cout << std::endl; }
    void prints() { print(); std::cout << ", "; }
    bool operator==(const Point2f other){
        if(x == other.x && y == other.y) {
            return true;
        }
        return false;
    }
    Point2f operator+(const Point2f other){
        Point2f t = *this;
        t.x = t.x + other.x;
        t.y = t.y + other.y;
        return t;
    }
    Point2f operator-(const Point2f other){
        Point2f t = *this;
        t.x = t.x - other.x;
        t.y = t.y - other.y;
        return t;
    }
    Point2f operator*(const double other){
        Point2f t = *this;
        t.x = t.x*other;
        t.y = t.x*other;
        return t;
    }
    Point2f operator/(const double other){
        Point2f t = *this;
        t.x = t.x/other;
        t.y = t.y/other;
        return t;
    }
    Point2f getRotatedPointAroundOtherPoint(Point2f point, float theta){
        float m = sqrt((point.x-x)*(point.x-x) + (point.y-y)*(point.y-y));
        m = 1/(100/m);
        Point2f temp;
        temp.x = (cos(theta) * (0-100)) - (sin(theta) * (0));
        temp.y = (sin(theta) * (0-100)) + (cos(theta) * (0));
        temp.x = temp.x * m;
        temp.y = temp.y * m;
        temp.x = temp.x + x;
        temp.y = temp.y + y;
        return temp;
    }
    Point2f getPointinBetween(Point2f point){
        Point2f temp(point.x-x, point.y-y);
        temp = temp/2;
        temp.x = temp.x+x;
        temp.y = temp.y+y;
        return temp;
    }
};

#endif /* Point2f_hpp */












