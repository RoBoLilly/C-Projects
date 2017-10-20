//
//  Area.hpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 7/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Area_hpp
#define Area_hpp

#include <stdio.h>
#include <vector>

enum AreaID { BlankArea, LoadedArea, StartArea, EndArea };

class Area {
private:
    AreaID ID;
    int areaSize[2];
public:
    Area(AreaID _ID, int x, int y);
    AreaID getID();
    int getAreaSize(int i);
    void resizeGrid(int x, int y);
    std::vector< std::vector<int> > gridIDs;
    std::vector< std::vector<bool> > gridRaised;
};

#endif /* Area_hpp */
