//
//  Point.cpp
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Point.hpp"

Point::Point(int x, int y){
    X = x;
    Y = y;
    state = 0;
}
Point::Point(){
    X = 0;
    Y = 0;
    state = 0;
}

void Point::setState(int i){
    state = i;
}
int Point::getState(){
    return state;
}

void Point::setPoint(Point pnt){
    X = pnt.X;
    Y = pnt.Y;
}
void Point::setPoint(int x, int y){
    X = x;
    Y = y;
}
