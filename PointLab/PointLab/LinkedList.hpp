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
    Partical data;
};

class LinkedList {
private:
    int IDcounter;
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    template <typename T>
    void insertFront(T data)
    {
        Node *temp=new Node;
        temp->data = data;
        temp->data.ID = IDcounter;
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
    };
    
    template <typename T>
    void insertBack(T data)
    {
        Node *temp=new Node;
        temp->data = data;
        temp->data.ID = IDcounter;
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
    };
    void deleteFront()
    {
        Node *temp=new Node;
        temp=head;
        head=head->next;
        delete temp;
    }
    void deleteBack()
    {
        Node *temp=new Node;
        temp=tail;
        tail=tail->next;
        delete temp;
    }
    void cleanUp()
    {
        while(head != nullptr) {
            deleteFront();
        }
    }
};

#endif /* LinkedList_hpp */
