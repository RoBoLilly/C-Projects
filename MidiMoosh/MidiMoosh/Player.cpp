//
//  Player.cpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 8/2/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Player.hpp"

Player::Player(AreaID areaID, int x, int y)
{
    MapLocation = areaID;
    gridLocation[0] = x;
    gridLocation[1] = y;
}

int Player::getGridLocation(int i)
{
    return gridLocation[i];
}

void Player::setGridLocation(int x, int y)
{
    gridLocation[0] = x;
    gridLocation[1] = y;
}

void Player::setMapLocation(AreaID ID)
{
    MapLocation = ID;
}

AreaID Player::getMapLocation()
{
    return MapLocation;
}

bool Player::move(Direc Direction, Map map)
{
    switch (Direction) {
            
        case UP:
            if (map.getGridRaised(gridLocation[0], gridLocation[1] - 1) == 0){
                this->gridLocation[1] = gridLocation[1] - 1;
            }
            break;
            
        case LEFT:
            if (map.getGridRaised(gridLocation[0] - 1, gridLocation[1]) == 0){
                this->gridLocation[0] = gridLocation[0] - 1;
            }
            break;
            
        case DOWN:
            if (map.getGridRaised(gridLocation[0], gridLocation[1] + 1) == 0){
                this->gridLocation[1] = gridLocation[1] + 1;
            }
            break;
            
        case RIGHT:
            if (map.getGridRaised(gridLocation[0] + 1, gridLocation[1]) == 0){
                this->gridLocation[0] = gridLocation[0] + 1;
            }
            break;
    }
    return true;
}
