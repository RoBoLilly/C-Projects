//
//  Sorter.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include "Sorter.hpp"
#include "List.hpp"
#include "TotalSwaps.h"

using namespace std;

Sorter::Sorter(List &List, SorterState State, Swaps &Swaps) {
    state = State;
    swaps = &Swaps;
    switch (state) {
        case NULL_SORT : {}break;
        case BUBBLE_SORT : {
            bubbleSort.list = &List;
            bubbleSort.swaps = swaps;
        }break;
        case TOP_SORT : {
            topSort.list = &List;
            topSort.swaps = swaps;
        }break;
        case RADIX_SORT : {
            radixSort.init(List);
            radixSort.swaps = swaps;
        }break;
        default:break;
    }
}

void Sorter::setState(SorterState State, List &List) {
    state = State;
    switch (state) {
        case NULL_SORT : {}break;
        case BUBBLE_SORT : {
            bubbleSort.list = &List;
            bubbleSort.swaps = swaps;
        }break;
        case TOP_SORT : {
            topSort.list = &List;
            topSort.swaps = swaps;
        }break;
        case RADIX_SORT : {
            radixSort.list = &List;
            radixSort.swaps = swaps;
            //radixSort.init();
        }break;
        default:break;
    }
}

SorterState Sorter::getState() { return state; }

int Sorter::getIndex() {
    switch (state) {
        case NULL_SORT : { return 0; }break;
        case BUBBLE_SORT : {
            return bubbleSort.index;
        }break;
        case TOP_SORT : {
            return topSort.index;
        }break;
        case RADIX_SORT : {
            return radixSort.index;
        }break;
    }
}

void Sorter::setIndex(int Index) {
    switch (state) {
        case NULL_SORT : {}break;
        case BUBBLE_SORT : {
            bubbleSort.index = Index;
        }break;
        case TOP_SORT : {
            topSort.index = Index;
        }break;
        case RADIX_SORT : {
            radixSort.index = Index;
        }break;
        default:break;
    }
}

void Sorter::resetSwaps() { swaps->resetSwaps(); }

void Sorter::iterateSwaps() { swaps->addOneToSwaps(); };

int Sorter::getSwaps() { return swaps->getSwaps(); }

void Sorter::resetTotalSwaps() {  }

int Sorter::getTotalSwaps() { return swaps->getTotal(); }

void Sorter::setList(List &List) {
    switch (state) {
        case NULL_SORT : {}break;
        case BUBBLE_SORT : {
            bubbleSort.list = &List;
        }break;
        case RADIX_SORT : {
            radixSort.list = &List;
        }break;
        default:break;
    }
}

List* Sorter::getList() {
    switch (state) {
        case NULL_SORT : { return 0; }break;
        case BUBBLE_SORT : {
            return bubbleSort.list;
        }break;
        case TOP_SORT : {
            return topSort.list;
        }break;
        case RADIX_SORT : {
            return radixSort.list;
        }
        default:break;
    }
}

bool Sorter::ifSuccsess() { return succsess; }

bool Sorter::Sort()
{
    succsess = false;
    switch (state) {
        case NULL_SORT : {}break;
        case BUBBLE_SORT : {
            if ( bubbleSort.Sort() ) { succsess = true; }
        }break;
        case TOP_SORT : {
            if ( topSort.Sort() ) { succsess = true; }
        }break;
        case RADIX_SORT : {
            if ( radixSort.Sort() ) { succsess = true; }
        }break;
        default:break;
    }
    return succsess;
}
































