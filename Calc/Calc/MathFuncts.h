//
//  MathFuncts.h
//  Calc
//
//  Created by Lilly Fiorino on 8/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef MathFuncts_h
#define MathFuncts_h
#include <math.h>

float pythagorean(float x, float y) {
    float out;
    out = sqrt((x*x)+(y*y));
    return out;
}
// f(x) = sqrt(x^2 + y^2)

float power(float x, float pow) {
    float out = x;
    for (int i = 0; i < pow-1; i++) {
        out = out * out;
    }
    return out;
}
// f(x) = x^pow

float derivative(float (*f)(float), float x, float dx) {
    float x1 = x + dx;
    float x2 = x;
    float out = (*f)(x1) - (*f)(x2);
    out = out/(x1 - x2);
    return out;
}
// f(x) = f(x1) - f(x2) / x1 - x2
// x1 = x + DeltaX/2
// x2 = x - DeltaX/2
float secondDerivative(float (*f)(float), float x) {
    float dx = 0.001;
    float out = derivative(*f, x+dx, dx) - derivative(*f, x, dx);
    out = out / dx;
    return out;
}

#endif /* MathFuncts_h */
