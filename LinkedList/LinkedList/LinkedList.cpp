//
//  LinkedList.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 9/6/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::createNode(int Value, int Index)
{
    size++;
    Node* temp = new Node;
    temp->data.value = Value;
    temp->data.index = Index;
    temp->next = nullptr;
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

int LinkedList::getValue(int index) {
    int i = 0;
    Node* temp = head;
    for (temp = head; temp != nullptr; temp = temp->next) {
        if ( i == index ) { return temp->data.value; }
        i++;
    }
    return 0;
}

void LinkedList::setValue(int index, int value) {
    int i = 0;
    Node* temp = head;
    for (temp = head; temp != nullptr; temp = temp->next) {
        if ( i == index ) { temp->data.value = value; break; }
        i++;
    }
}
void LinkedList::deleteNode(int Index) {
    
};

