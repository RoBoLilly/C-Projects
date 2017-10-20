//
//  Stanly.hpp
//  Stan(ly)
//
//  Created by Lilly Fiorino on 6/15/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Stanly_hpp
#define Stanly_hpp

#include <stdio.h>

class RadialPoint{
public:
    RadialPoint(){
        R = 0;
        A = 0;
    }
    double R;
    double A;
};

class Stanly {
public:
    Stanly();
    double location[0];
    double angle;
    RadialPoint Map[256];
    void render();
private:
};

#endif /* Stanly_hpp */
