#pragma once

class player {
    private:
        int location[2];
        int inventory[10];
        int inventorySize;
    public:
        int getLocation(int i);
        void setLocation(int i, int coord);
        int getInventory(int i);
        void setInventory(int i, int j);
        int getInventorySize();
        void setInventorySize(int i);
};