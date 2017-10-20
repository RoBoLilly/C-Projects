//
//  Point.hpp
//
//  Created by Lilly Fiorino on 6/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point
{
public:
    Point();
    Point(int x, int y);
    int X;
    int Y;
    int state;
    void setState(int i);
    int getState();
    void setPoint(Point pnt);
    void setPoint(int x, int y);
};

#endif /* Point_hpp */


