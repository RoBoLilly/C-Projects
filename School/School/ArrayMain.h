//
//  ArrayMain.h
//  School
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <iostream>

float exponent( float base, int power )
{
    if (power == 0) { return 1; } // if power equals 0 return 1
    bool negPower = power < 0;    // true if the power is negitive
    if (negPower) { power = -1 * power; } // swap sign of power if negPower is true
    float output = base; // set output float to base to begin
    int c = 1; // set loop couter to 1
    while(c < power) { // loop while couter smaller than power
        output = output * base; // multiply the base by itself power times
        c++; // increment loop couter
    };
    if (negPower) { output = 1.0f / output; } // if negPower is ture divide 1 by the output
    return output;
}

int ArrayMain() {
    
    int size = 10;
    float array[size]; // define array
    
    for (int i = 0; i < size; i++) { // fill array with ascending list
        array[i] = i;
    }
    
    for (int i = 0; i < size; i++) { // print array
        std::cout << array[i] << ", ";
    }std::cout << std::endl << std::endl;
    
    for (int i = 0; i < size; i++) { // square every item in array
        array[i] = exponent(array[i], -1);
    }
    
    for (int i = 0; i < size; i++) { // print array
        std::cout << array[i] << ", ";
    }std::cout << std::endl;
    
    return 0;
}

#endif /* Array_h */
