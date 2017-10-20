//
//  RadixSort.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 9/5/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef RadixSort_hpp
#define RadixSort_hpp

#include "List.hpp"
#include "TotalSwaps.h"
#include "LinkedList.hpp"
#include <vector>
#include <stdio.h>
#include <iostream>


class RadixSort {
private:
public:
    enum State { PREPARE, PLACE, CLEAR };
    RadixSort() {
        index = 0;
    }
    Swaps* swaps;
    List* list;
    State state;
    int count = 0;
    int index;
    int div = 1;
    int k = 0;
    int i = 0;
    int j = 0;
    std::vector<LinkedList> buffer;
    void init(List &List);
    bool Sort();
};

#endif /* RadixSort_hpp */
