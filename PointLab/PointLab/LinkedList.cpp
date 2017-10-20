//
//  LinkedList.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "LinkedList.hpp"
#include "Partical.hpp"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::insertBack(Partical p) {
    Node *temp=new Node;
    temp->partical = p;
    temp->partical.ID = IDcounter;
    IDcounter++;
    temp->prev = nullptr;
    if(tail == nullptr)
    {
        head=temp;
        tail=temp;
        temp=nullptr;
    }
    else
    {
        head->next=temp;
        head=temp;
    }
}

void LinkedList::insertFront(Partical p) {
    Node *temp=new Node;
    temp->partical = p;
    temp->partical.ID = IDcounter;
    IDcounter++;
    temp->next = nullptr;
    if(head == nullptr)
    {
        head=temp;
        tail=temp;
        temp=nullptr;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
void LinkedList::cleanUp()
{
    while(head != nullptr) {
        deleteFront();
    }
}

void LinkedList::deleteFront()
{
    Node *temp=new Node;
    temp=head;
    head=head->next;
    delete temp;
}
void LinkedList::deleteBack()
{
    Node *temp=new Node;
    temp=tail;
    tail=tail->next;
    delete temp;
}

