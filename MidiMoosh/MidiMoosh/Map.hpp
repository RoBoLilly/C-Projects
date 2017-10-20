//
//  Map.hpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 7/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include "Area.hpp"

class Map {
private:
    Area blankArea;
    Area loadedArea;
    Area startArea;
    Area endArea;
public:
    Map();
    void printArea();
    void clearArea();
    bool loadArea(AreaID ID);
    int getGridID(int x, int y);
    void setGridID(int x, int y, int i);
    bool getGridRaised(int x, int y);
    void setGridRaised(int x, int y, bool i);
    AreaID getAreaID();
};

#endif /* Map_hpp */
