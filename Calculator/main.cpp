#include <iostream>
#include <string>
#include <math.h>
using namespace std;

enum CalcOp {Add, Sub, Mut, Div};

CalcOp getOperator();

float calculate(float q1[], CalcOp Op[], int j);

int main(){
    cout << "Calculation: " << endl;
    CalcOp op[10];
    float in1[10];
    static int j = 0;
    string ck;
        cin >> in1[j];
    while(ck != "|"){
        op[j] = getOperator();
        j++;
        cin >> in1[j];
        cin >> ck;
    }
    float out = calculate(in1, op, j);

    cout << "Out: " << out << endl;

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

float calculate(float q1[], CalcOp Op[], int j){
    static int i = 0;
    float var = q1[i];
    while(i < j){
        cout << "~";
        switch(Op[i]){
            case Add:
                var = var + q1[i];
            case Sub:
                var = var - q1[i];
            case Mut:
                var = var * q1[i];
            case Div:
                var = var / q1[i];
            default:
                var = var * q1[i];
            }
    j--;
    i++;
    }
    return var;
    // switch(Op){
    //     case Add:
    //         return q1 + q2;
    //     case Sub:
    //         return q1 - q2;
    //     case Mut:
    //         return q1 * q2;
    //     case Div:
    //         return q1 / q2;
    //     default:
    //         return q1 * q2;
    // }
}