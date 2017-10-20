//
//  Function.cpp
//  Calc
//
//  Created by Lilly Fiorino on 10/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Function.hpp"

Function::Function() {}
Function::Function( float (*f)(float) ) {
    member = f;
}

float Function::operator()(float x) {
    return (*member)(x);
}

void Function::setMember(float (*mem)(float)) {
    member = mem;
}
