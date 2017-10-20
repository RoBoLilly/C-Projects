#include "enemy.h"

void enemy::setLocation(int i, int j){
    location[i] = j;
}
int enemy::getLocation(int i){
    return location[i];
}
int enemy::getMapLocation(int i){
    return mapLocation[i];
}
void enemy::setMapLocation(int i, int j){
    mapLocation[i] = j;
}
void enemy::moveForward(){
    if(location[0] != 0){location[0] = location[0] - 1;}
}
void enemy::moveBackward(){
    if(location[0] != 11){location[0] = location[0] + 1;}
}
void enemy::moveLeft(){
    if(location[1] != 0){location[1] = location[1] - 1;}
}
void enemy::moveRight(){
    if(location[1] != 11){location[1] = location[1] + 1;}
}
// AI
int enemy::getAIstate(){
    return AIstate;
}
void enemy::setAIstate(int i){
    AIstate = i;
}
int enemy::attackForward(){
    return 0;
}
int enemy::attackBackward(){
    return 0;
}
int enemy::attackLeft(){
    return 0;
}
int enemy::attackRight(){
    return 0;
}