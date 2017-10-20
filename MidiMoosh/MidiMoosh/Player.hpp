//
//  Player.hpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 8/2/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Map.hpp"
#include "Area.hpp"

enum Direc { UP, LEFT, DOWN, RIGHT };

class Player {
private:
    int gridLocation[2];
    AreaID MapLocation;
public:
    Player(AreaID areaID, int x, int y);
    int getGridLocation(int i);
    void setGridLocation(int x, int y);
    void setMapLocation(AreaID ID);
    AreaID getMapLocation();
    bool move(Direc Direction, Map map);
};

#endif /* Player_hpp */
