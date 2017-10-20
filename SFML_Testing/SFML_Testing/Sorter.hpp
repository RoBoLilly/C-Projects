//
//  Sorter.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Sorter_hpp
#define Sorter_hpp

#include <stdio.h>
#include "List.hpp"
#include "BubbleSort.hpp"
#include "TopSort.hpp"
#include "RadixSort.hpp"
#include "TotalSwaps.h"


enum SorterState { NULL_SORT, BUBBLE_SORT, TOP_SORT, RADIX_SORT };


class Sorter {
private:
    Swaps* swaps;
    SorterState state;
    BubbleSort bubbleSort;
    TopSort topSort;
    RadixSort radixSort;
    bool succsess;
public:
    Sorter(List &List, SorterState State, Swaps &Swaps);
    void setState(SorterState State, List &List);
    SorterState getState();
    void setIndex(int Index);
    int getIndex();
    void resetSwaps();
    void iterateSwaps();
    int getSwaps();
    void resetTotalSwaps();
    int getTotalSwaps();
    void setList(List &List);
    List* getList();
    bool Sort();
    bool ifSuccsess();
};


#endif /* Sorter_hpp */
