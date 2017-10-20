//
//  Wire.cpp
//  Ohm's_Law
//
//  Created by Lilly Fiorino on 6/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Wire.hpp"
#include "Point.hpp"

Wire::Wire(Point P0, Point P1)
{
    p0.X = P0.X;
    p0.Y = P0.Y;
    p1.X = P1.X;
    p1.Y = P1.Y;
}
