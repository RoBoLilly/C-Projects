//
//  StateMachine.hpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/24/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <stdio.h>

enum State { IDLE, SORT, SUCCSESS, START };

class StateMachine {
private:
public:
    StateMachine(State State);
    State state;
};

#endif /* StateMachine_hpp */
