//
//  BubbleSort.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/27/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include "List.hpp"
#include "TotalSwaps.h"
#include <stdio.h>

class BubbleSort {
public:
    BubbleSort() {
        index = 0;
    }
    Swaps* swaps;
    List* list;
    int index;
    int lim;
    void init();
    
    bool Sort()
    {
        bool succsess = false;
        if ( list->get(index) > list->get(index+1) ) {
            list->swapItems(index, index+1);
            swaps->addOneToSwaps();
            swaps->addOneToTotal();
        }
        
        if (index == list->Size()) { index = 0; }
        
        for (int i = list->Size(); i >= 0; i--) {
            if(list->get(i-1)<list->get(i-2)) { lim = i; break; }
            if(i == 0){
                succsess = true;
            }
        }
        index++;
        if (index > lim) {index = 0;}
        return succsess;
    }
    
};

#endif /* BubbleSort_hpp */
