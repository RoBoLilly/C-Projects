//
//  List.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/24/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "List.hpp"
#include <iostream>

List::List( int size )
{
    listSize = size;
    list.resize(listSize);
    for (int i = 0; i < listSize; i++) {
        list[i] = 0;
    }
}

int List::get( int index )
{
    if ( index < listSize && index >= 0 ) {
        return list[index];
    } else {
        return 0;
    }
}

bool List::set( int index, int data ) {
    if ( index < listSize && index >= 0 )
    {
        list[index] = data;
        return true;
    } else {
        return false;
    }
}

bool List::swapItems( int index1, int index2 ) {
    if ( index1 < listSize && index1 >= 0 )
    {
        if ( index2 < listSize && index2 >= 0 )
        {
            int buffer = list[index1];
            list[index1] = list[index2];
            list[index2] = buffer;
            return 1;
            
        } else { return 0; }
    } else { return 0; }
}

int List::Size() {
    return listSize;
}

void List::fillRand(int max) {
    maximum = max;
    for (int i = 0; i < listSize; i++) {
        list[i] = (int)rand()% maximum;
        //list[i] = i;
    }
}

int List::Max() { return maximum; }

void List::setSize(int Size) {
    listSize = Size;
    list.resize(Size);
}




