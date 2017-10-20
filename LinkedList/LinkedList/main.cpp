//
//  main.cpp
//  LinkedList
//
//  Created by Lilly Fiorino on 9/7/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    LinkedList list;
    
    list.createNode(12, 0);
    list.createNode(34, 0);
    list.createNode(52, 0);
    list.createNode(66, 0);
    list.createNode(32, 0);
    list.createNode(234, 0);
    
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list.getValue(i) << ", ";
    }
    std::cout << std::endl;
    
    
    
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list.getValue(i) << ", ";
    }
    std::cout << std::endl;
    return 0;
}
