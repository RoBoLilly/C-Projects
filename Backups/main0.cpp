#include <iostream>
#include <math.h>
using namespace std;
 
float scaler = .5;
int vec0[] = {2,4};
int vec1[] = {3,2};
const int vec0s = sizeof(vec0)/sizeof(*vec0); // Number of elements in vec0
const int vec1s = sizeof(vec1)/sizeof(*vec1); // Number of elements in vec1
int vecO[vec1s];
int addVec[] = {(vec0[0]+vec1[0]), (vec0[1]+vec1[1])};
int proVec0[] = {(vec0[0]*vec1[0])+(vec0[0]*vec1[1]),(vec0[1]*vec1[0])+(vec0[1]*vec1[1])};
int proVec1[] = {(vec1[0]*vec0[0])+(vec1[0]*vec0[1]),(vec1[1]*vec0[0])+(vec1[1]*vec0[1])};

int* matM(int vecA[], int vecB[]);
int pE(int vec[], int size);
 
int main() {

	proVec0[0] = proVec0[0]*scaler;
	proVec0[1] = proVec0[1]*scaler;
	proVec1[0] = proVec1[0]*scaler;
	proVec1[1] = proVec1[1]*scaler;

	int var0 = proVec1[0]-addVec[0];
	int var1 = proVec0[1]-addVec[1];
	float h = sqrt(pow(var0,2)+pow(var1,2));

	// Print Code
	cout << "vec0:" << vec0[0] <<","<< vec0[1] << endl;
	cout << "vec1:" << vec1[0] <<","<< vec1[1] << endl;
	cout << "addVec:" << addVec[0] <<","<< addVec[1] << endl;
	cout << "proVec0:" << proVec0[0] <<","<< proVec0[1] << endl;
	cout << "proVec1:" << proVec1[0] <<","<< proVec1[1] << endl;
	cout << "var0:" << var0 << endl;
	cout << "var1:" << var1 << endl;
	cout << "H:" << h << endl;
	cout << "var0 and var1 are ";

	if (var0 == var1){
		cout << "equal" << endl;
	}else{
		cout << "not equal" << endl;
	}
}

int* matM(int vecA[], int vecB[]){ // Matrix Product Function
	for(int a=0;a < vec0s; a++){
		for(int b=0;b < vec1s; b++){
			vecO[a] = vecO[a]+(vecA[a]*vecB[b]);
		}
	}	
	int* vecP = vecO;
	return vecP;
}

int pE(int vec[], int size){ // Prints Elements in Array
	for(int a=0; a < size; a++){
	if(a < size-1){
	cout << vec[a] << ",";
	}else{
		cout << vec[a];
	}
}cout << endl;
return 0;
}