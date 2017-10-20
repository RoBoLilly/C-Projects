//
//  Function.hpp
//  Calc
//
//  Created by Lilly Fiorino on 10/8/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>

class Function {
private:
    float (*member)(float);
public:
    Function();
    Function(float (*f)(float));
    float operator()(float x);
    void setMember(float (*mem)(float));
};


#endif /* Function_hpp */
