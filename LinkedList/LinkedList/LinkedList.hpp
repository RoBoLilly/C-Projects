//
//  LinkedList.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 9/6/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

struct Node {
    struct Data {
        int value;
        int index;
    };
    Data data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size = 0;
public:
    LinkedList();
    int getValue(int index);
    void setValue(int index, int value);
    int getSize();
    void createNode(int Value, int Index);
    void deleteNode(int Index);
};

#endif /* LinkedList_hpp */
