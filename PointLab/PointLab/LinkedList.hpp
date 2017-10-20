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

template <typename type>
struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    type data;
};

template <typename type>
class LinkedList {
private:
    int IDcounter;
public:
    Node<type>* head;
    Node<type>* tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    template <typename T>
    void insertFront(T data)
    {
        Node<type> *temp=new Node<type>;
        temp->partical = data;
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
    };
    
    template <typename T>
    void insertBack(T data)
    {
        Node<type> *temp=new Node<type>;
        temp->partical = data;
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
    };
    void deleteFront()
    {
        Node<type> *temp=new Node<type>;
        temp=head;
        head=head->next;
        delete temp;
    }
    void deleteBack()
    {
        Node<type> *temp=new Node<type>;
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
