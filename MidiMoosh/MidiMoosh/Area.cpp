//
//  Area.cpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 7/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Area.hpp"

Area::Area(AreaID _ID, int x, int y)
{
    resizeGrid(x, y);
    areaSize[0] = x;
    areaSize[1] = y;
    ID = _ID;
}

AreaID Area::getID()
{
    return ID;
}

int Area::getAreaSize(int i)
{
    return areaSize[i];
}

void Area::resizeGrid(int x, int y)
{
    this->gridIDs.resize(y);
    this->gridRaised.resize(y);
    this->gridIDs[0].resize(x);
    this->gridRaised[0].resize(x);
    this->areaSize[0] = x;
    this->areaSize[1] = y;
    this->gridIDs.resize(y);
    this->gridRaised.resize(y);
    for(int i=0; i<16; i++){
        this->gridIDs[i].resize(x);
        this->gridRaised[i].resize(x);
    }
}
