//
//  List.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/24/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <vector>

class List {
private:
    std::vector<int> list;
    int listSize;
    int maximum;
public:
    List( int size );
    int get(int index);
    bool set(int index, int data);
    bool swapItems(int index1, int index2);
    int Size();
    void setSize(int Size);
    void fillRand(int max);
    int Max();
};

#endif /* List_hpp */
