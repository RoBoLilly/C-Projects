//
//  Swaps.h
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/27/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Swaps_h
#define Swaps_h

class Swaps {
private:
    int total;
    int swaps;
public:
    int getTotal() { return total; }
    int getSwaps() { return swaps; }
    void addOneToTotal() { total++; };
    void addOneToSwaps() { swaps++; };
    void resetTotal() { total = 0; }
    void resetSwaps() { swaps = 0; }
};

#endif /* Swaps_h */
