//
//  Mains.hpp
//  School
//
//  Created by Lilly Fiorino on 10/11/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Mains_hpp
#define Mains_hpp

#include <stdio.h>
#include "Main1.hpp"
#include "ArrayMain.h"

int Mains(int index) {
    switch(index) {
        case 0: {
            return ArrayMain();
        } break;
        default: {
            return Main1();
        } break;
    }
}

#endif /* Mains_hpp */
