#include <iostream>
#include <string>
#include <math.h>
using namespace std;

enum CalcOp {Add, Sub, Mut, Div};

CalcOp getOperator();

float calculate(float q1, float q2, CalcOp Op);

int main(){
    CalcOp op;
    cout << "Calculation: ";
    float a;
    float b;
    cin >> a;
    op = getOperator();
    cin >> b;
    float out = calculate(a, b, op);
    cout << out << endl;

    return 0;
}

CalcOp getOperator(){
    string var;
    cin >> var;
    if(var == "+"){
        return Add;
    }
    if(var == "-"){
        return Sub;
    }
    if(var == "*"){
        return Mut;
    }
    if(var == "/"){
        return Div;
    }else{
        return Mut;
    }
}

float calculate(float q1, float q2, CalcOp Op){
    switch(Op){
        case Add:
            return q1 + q2;
        case Sub:
            return q1 - q2;
        case Mut:
            return q1 * q2;
        case Div:
            return q1 / q2;
        default:
            return q1 * q2;
    }
}