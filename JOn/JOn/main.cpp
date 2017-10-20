//
//  main.cpp
//  JOn
//
//  Created by Lilly Fiorino on 6/2/17.
//  Copyright © 2017 Cibo. All rights reserved.
//
#include <iostream>
using namespace std;

bool isBigger(int a, int b);

int main()
{
    int akd  = 12;
    int bdf = 45;

    isBigger(akd, bdf);
    
    
    cout << " awda "<< endl;
    
}

bool isBigger(int a, int b){
    if(a>b){
        cout << " A > B "<< endl;
        return true;
    }else{
        cout << " A < B " << endl;
        return false;
    }
}
