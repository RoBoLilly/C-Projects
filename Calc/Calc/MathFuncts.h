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

const double pi = 3.14159;

double pythagorean(double x, double y) {
    double out;
    out = sqrt((x*x)+(y*y));
    return out;
}
// f(x) = sqrt(x^2 + y^2)

double power(double x, double pow) {
    double out = x;
    for (int i = 0; i < pow-1; i++) {
        out = out * out;
    }
    return out;
}
// f(x) = x^pow

double derivative(double (*f)(double), double x, double dx) {
    double out = (*f)(x + dx) - (*f)(x);
    out = out/((x+dx)-x);
    return out;
}
// f(x) = f(x1) - f(x2) / x1 - x2
// x1 = x + DeltaX/2
// x2 = x - DeltaX/2
double secondDerivative(double (*f)(double), double x) {
    double dx = 0.001;
    double out = derivative(*f, x+dx, dx) - derivative(*f, x, dx);
    out = out / dx;
    return out;
}

#endif /* MathFuncts_h */
