//
//  main.cpp
//  Struts
//
//  Created by Lilly Fiorino on 6/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <fstream>
#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
//#include "SDL_Init.h"
using namespace std;

int main( int argc, char* args[] )
{
    
    ifstream file;
    file.open("data.dat");
    
    char data[100];
    
    file >> data;
    cout << "KILL" << endl;
    cout << data << endl;
    file.close();

}
