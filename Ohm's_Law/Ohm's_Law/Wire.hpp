//
//  Wire.hpp
//  Ohm's_Law
//
//  Created by Lilly Fiorino on 6/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Wire_hpp
#define Wire_hpp

#include <stdio.h>
#include "Point.hpp"

class Wire
{
public:
    Wire(Point p0, Point p1);
    Point p0, p1;
};

#endif /* Wire_hpp */
