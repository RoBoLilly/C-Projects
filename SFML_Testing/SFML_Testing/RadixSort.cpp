//
//  RadixSort.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 9/6/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "RadixSort.hpp"
#include "RadixSupport.hpp"
#include <iostream>

void RadixSort::init(List &List) {
    list = &List;
    state = RadixSort::PREPARE;
    index = 0;
    buffer.resize(10);
}


bool RadixSort::Sort()
{
    bool succsess = false;
    switch (state) {
        case PREPARE : {
            int q = list->get(index)%(10*div);
            q = q/div;
            //std::cout << "Q:" << q << std::endl;
            count++;
            buffer[q].createNode(list->get(index), index);
            //std::cout << buffer[q].getSize() << ", ";
            index++;
            if (index >= list->Size()) { index = 0; state = PLACE; }
        }break;
        case PLACE : {
            list->set(k, buffer[i].getValue(j));
            k++;
            if (j <= buffer[i].getSize()) {j++;} else {j=0; i++;}
            if (k == list->Size()) { k = 0; i = 0;}
            div = div * 10;
            state = CLEAR;
            //succsess = true;
        }break;
        case CLEAR : {
            for(int i = 0; i < 10; i++) {
//                for(int k = 0; k < buffer[i].getSize(); k++) {
//                    std::cout << buffer[i].getValue(k) << ",";
//                }std::cout << std::endl;
                buffer[i].clear();
            }
            for (int i = list->Size(); i >= 0; i--) {
                if(list->get(i-1)<list->get(i-2)) { break; }
                if(i == 0){
                    std::cout << "C: " << count << std::endl;
                    count = 0;
                    index = 0;
                    div = 1;
                    state = PREPARE;
                    return true;
                }
            }
            state = PREPARE;
        }break;
            
    }
    
    return succsess;
}
