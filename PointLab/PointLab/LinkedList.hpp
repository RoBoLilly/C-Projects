//
//  LinkedList.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "Partical.hpp"

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    Partical partical;
};

class LinkedList {
private:
    int IDcounter;
public:
    Node* head;
    Node* tail;
    LinkedList();
    void insertFront(Partical p);
    void insertBack(Partical p);
    void deleteFront();
    void deleteBack();
    void cleanUp();
};

#endif /* LinkedList_hpp */
