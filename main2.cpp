#include <iostream>
using namespace std;

int vec0[] = {2,4};
int vec1[] = {3,2};
const int vec0s = sizeof(vec0)/sizeof(*vec0); // Number of elements in vec0
const int vec1s = sizeof(vec1)/sizeof(*vec1); // Number of elements in vec1
int vecO[vec1s];

int* matM(int vecA[], int vecB[]);
int pE(int vec[], int size);

int main () {
	
	pE(vec0, vec0s);
	pE(vec1, vec1s);
	
	int* preVec0 = matM(vec0, vec1);
	int proVec0[vec0s];
	for (int a=0;a< vec0s;a++){
		proVec0[a] = preVec0[a];
	}
	
	int* preVec1 = matM(vec1, vec0)
	int proVec1[vec1s];
	for (int a=0;a< vec1s;a++){
		proVec1[a] = preVec1[a];
	}
	pE(proVec0, 2);
	pE(proVec1, 2);
	

}

int* matM(int vecA[], int vecB[]){ // Matrix Product Function
	int var = vecB[0] + vecB[1];
	vecO[0] = vecA[0]*var;
	vecO[1] = vecA[1]*var;
	int* vecP = vecO;
	return vecP;
}

int pE(int vec[], int size){
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


/*

	for(int a=0;a < vec0s; a++){
		for(int b=0;b < vec1s; b++){
			vecO[a] += (vecA[a]*vecB[b]);
		}
		}
		
*/