//
//  TopSort.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef TopSort_hpp
#define TopSort_hpp

#include "List.hpp"
#include "TotalSwaps.h"
#include <stdio.h>

class TopSort {
public:
    TopSort() {
        index = 0;
    }
    Swaps* swaps;
    List* list;
    int index;
    int lim = 0;
    struct Min {
        int index = 0;
        int value = 0;
    };
    int swapIndex;
    void init();
    
    bool Sort()
    {
        const int Lsize = list->Size();
        if (index >= Lsize || lim >= Lsize) { index = 0; lim = 0; }
        
        for (int i = Lsize; i >= 0; i--) {
            if(list->get(i-1)<list->get(i-2)) { break; }
            if(i == 0){
                index = 0;
                lim = 0;
                return true;
            }
        }
        Min min;
        min.value = list->Max();
        for (int i = lim; i < Lsize; i++) {
            if (list->get(i) < min.value) {
                min.value = list->get(i);
                min.index = i;
            }
        }
        list->swapItems(index, min.index);
        swaps->addOneToSwaps();
        swaps->addOneToTotal();
        lim++;
        index++;
        return false;
    }
};

#endif /* TopSort_hpp */
