#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
float scaler = .5;
int vec0[] = {2,4};// Input Vectors
int vec1[] = {3,2};
int vec2[] = {6,2};

const int vec0s = sizeof(vec0)/sizeof(*vec0); // Number of elements in vec0
const int vec1s = sizeof(vec1)/sizeof(*vec1); // Number of elements in vec1
const int vec2s = sizeof(vec1)/sizeof(*vec1); // Number of elements in vec1

int proVec0[vec0s];
int proVec1[vec0s];
int proVec2[vec0s];
int proVec3[vec0s];
int proVec4[vec0s];
int proVec5[vec0s];

int addVec0[vec0s];
int addVec1[vec0s];
int addVec2[vec0s];
int addVec3[vec0s];
int addVec4[vec0s];
int addVec5[vec0s];

int addV(int vecA[], int vecB[], int outVec[]);
int matM(int vecA[], int vecB[], int outVec[], int s0, int s1);
int pE(int vec[], int size = 2);
float vecD(int vecA[],int vecB[]);
 
int main() {

	cout << vecD(vec0, vec1) << endl; 
	
	
	addV(vec0, vec1, addVec0);
	addV(vec0, vec2, addVec1);
	addV(vec1, vec2, addVec2);
	
	matM(vec0, vec1, proVec0, vec0s, vec1s);
	matM(vec0, vec2, proVec1, vec0s, vec2s);
	matM(vec1, vec0, proVec2, vec1s, vec0s);
	matM(vec1, vec2, proVec3, vec1s, vec2s);
	matM(vec2, vec0, proVec4, vec2s, vec0s);
	matM(vec2, vec1, proVec5, vec2s, vec1s);
	
	proVec0[0] = proVec0[0]*scaler;
	proVec0[1] = proVec0[1]*scaler;
	
	proVec1[0] = proVec1[0]*scaler;
	proVec1[1] = proVec1[1]*scaler;
	
	proVec2[0] = proVec2[0]*scaler;
	proVec2[1] = proVec2[1]*scaler;
	
	proVec3[0] = proVec3[0]*scaler;
	proVec3[1] = proVec3[1]*scaler;
	
	proVec4[0] = proVec4[0]*scaler;
	proVec4[1] = proVec4[1]*scaler;
	
	proVec5[0] = proVec5[0]*scaler;
	proVec5[1] = proVec5[1]*scaler;
	

	int var0 = proVec1[0]-addVec0[0];
	int var1 = proVec0[1]-addVec0[1];
	float h = sqrt(pow(var0,2)+pow(var1,2));

	// Print Code
	cout << "vec0:"; pE(vec0);
	cout << "vec1:"; pE(vec1);
	cout << "vec2:"; pE(vec2);
	cout << "addVec0:"; pE(addVec0);
	cout << "addVec1:"; pE(addVec1);
	cout << "addVec2:"; pE(addVec2);
	
	cout << "proVec0:"; pE(proVec0);
	cout << "proVec1:"; pE(proVec1);
	cout << "proVec2:"; pE(proVec2);
	cout << "proVec3:"; pE(proVec3);
	cout << "proVec4:"; pE(proVec4);
	cout << "proVec5:"; pE(proVec5);
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

int addV(int vecA[], int vecB[], int outVec[]){ // Vector adder function
	outVec[0] = vecA[0] + vecB[0];
	outVec[1] = vecA[1] + vecB[1];
	return 0;
}

int matM(int vecA[], int vecB[], int outVec[], int s0, int s1){ // Matrix product function
	int var = 0;
	for(int a=0; a < s1; a++){
		var += vecB[a]; 
	}
	cout << var << endl;
	for(int b=0; b < s0; b++){
		outVec[b] = vecA[b]*var;
	}
	return 0;
}

int pE(int vec[], int size){ // Prints array in vector form
	cout << "[";
	for(int a=0; a < size; a++){
	if(a < size-1){
	cout << vec[a] << ",";
	}else{
		cout << vec[a];
	}
}cout << "]" << endl;
return 0;
}

float vecD(int vecA[], int vecB[]){ // finds distance between two vectors
	float var0;
	float var1;
	if (vecA[0]>vecB[0]){
	var0 = vecA[0] - vecB[0];
	}
	else if (vecA[0]<vecB[0]){
	var0 = vecB[0] - vecA[0];
	}
	if (vecA[1]>vecB[1]){
	var1 = vecA[1] - vecB[1];
	}
	else if (vecA[1]<vecB[1]){
	var1 = vecB[1] - vecA[1];
	}
	float rt = sqrt((var0*var0)+(var1*var1));
	return rt;

}






