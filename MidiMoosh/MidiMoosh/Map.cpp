//
//  Map.cpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 7/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include "Map.hpp"

Map::Map() :
blankArea(BlankArea, 16, 16),
loadedArea(LoadedArea, 16, 16),
startArea(StartArea, 16, 16),
endArea(EndArea, 16, 16) {
    
    // Starting area, where the player spawns
    
    startArea.gridIDs = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,2,2,2,2,2,2,0,0,0,0,1},
        {1,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,2,2,2,2,2,2,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    startArea.gridIDs[3][2] = 2;
    
    startArea.gridRaised = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,1,1,0,1,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    
    
    
    // Ending area, where the player trigers quit.
    
    endArea.gridIDs = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,2,2,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,2,2,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,2,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    for (int x=0; x<16; x++) {
        for (int y=0; y<16; y++) { endArea.gridRaised[x][y] = 0; }
    }
    
    
};


void Map::clearArea()
{
    loadedArea = blankArea;
}

void Map::printArea()
{
    for (int x=0; x<16; x++){
        for (int y=0; y<16; y++){
            std::cout << loadedArea.gridIDs[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

bool Map::loadArea(AreaID ID)
{
    switch(ID)
    {
        case LoadedArea:
            return false;
        case StartArea:
            loadedArea = startArea;
            break;
        case EndArea:
            loadedArea = endArea;
            break;
        default:
            return false;
    }
    return true;
}

int Map::getGridID(int x, int y)
{
    return loadedArea.gridIDs[x][y];
}

void Map::setGridID(int x, int y, int i)
{
    loadedArea.gridIDs[x][y] = i;
}

bool Map::getGridRaised(int x, int y)
{
    return loadedArea.gridRaised[x][y];
}
void Map::setGridRaised(int x, int y, bool i)
{
    loadedArea.gridRaised[x][y] = i;
}

AreaID Map::getAreaID()
{
    return loadedArea.getID();
}

//void Map::loadArea(Area inArea){
//    loadedArea = inArea;
//    loadedArea.ID = inArea.ID;
//    loadedArea.areaSize[0] = inArea.areaSize[0];
//    loadedArea.areaSize[1] = inArea.areaSize[1];
//    for(int x=0; x>16; x++){
//        for(int y=0; y>16; y++){
//            loadedArea.gridIDs[x][y] = inArea.gridIDs[x][y];
//            loadedArea.gridStates[x][y] = inArea.gridStates[x][y];
//        }
//    }
//}




