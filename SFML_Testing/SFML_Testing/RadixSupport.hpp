//
//  RadixSupport.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 9/12/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef RadixSupport_hpp
#define RadixSupport_hpp

#include <stdio.h>

class RadixLoad {
    RadixLoad();
};

class RadixPlace{
    RadixPlace();
};

class RadixClear{
    RadixClear();
};

class RadixSupport {
private:
public:
    RadixSupport();
    RadixLoad RLoad;
    RadixPlace RPlace;
    RadixClear RClear;
};



#endif /* RadixSupport_hpp */
