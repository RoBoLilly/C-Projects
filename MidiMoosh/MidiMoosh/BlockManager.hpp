//
//  BlockManager.hpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 8/3/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef BlockManager_hpp
#define BlockManager_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

enum BlockID { Grass, Stone, Wood };

class BlockManager {
public:
    void setColorByID(SDL_Renderer &gRenderer, BlockID ID);
};

#endif /* BlockManager_hpp */
