#include "player.h"

int player::getLocation(int i){
    return location[i];
}
void player::setLocation(int i, int coord){
    location[i] = coord;
}
int player::getInventory(int i){
    return inventory[i];
}
void player::setInventory(int i, int j){
    inventory[i] = j; 
}
int player::getInventorySize(){
    return inventorySize;
}
void player::setInventorySize(int i){
    inventorySize = i;
}