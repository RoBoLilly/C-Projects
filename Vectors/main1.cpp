#include <iostream>
#include <vector>
using namespace std;
vector<int> v1;
vector<int> v2;
vector<int> v3;

int main(){
	for(int i=0; i<10; i++){
		v1.push_back(i+1);
		//v2[i] = i*2;
		//v3[i] = i*i;
	}
	return 0;
}

