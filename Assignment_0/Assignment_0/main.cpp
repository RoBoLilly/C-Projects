//
//  main.cpp
//  Assignment_0
//
//  Created by Lilly Fiorino on 10/15/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include <iostream>

int pow(int base, int power)
{
    if(power == 0){ return 1; }
    int temp = base;
    int counter = 1;
    while(counter < power)
    {
        temp = temp * base;
        counter++;
    }
    return temp;
}

int main(int argc, const char * argv[])
{
    int power = 0;
    std::cout << "Give what power to stop at: ";
    int endPower;
    std::cin >> endPower;
    std::cout << "0 - " << endPower << std::endl;
    std::cout << "Give base number to do power on: ";
    int base;
    std::cin >> base;
    std::cout << std::endl;
    while (power <= endPower) {
        int out;
        out = pow(base, power);
        std::cout << base << "^" << power << ": " << out << std::endl;
        power++;
    }
    return 0;
}

