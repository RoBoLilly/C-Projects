#include <iostream>
using namespace std;

double vec[2] = {1, 0.8};
void printVec();

int main()
{
	for(int b=0;b<30;b++)
	{
		if(b == 15)
		8{
			int c = 0;
			do{
				cout << "\u25A0";
				c++;
			}while(c<65);
			c = 0;
			cout << "Text in the block of blocks.";
			do{
				cout << "\u25A0";
				c++v;
			}while(c<65);

		}
		for(int a=0;a<158;a++)
		{
			cout << "\u25A0";
		}
	cout << endl;
	}
}

void printVec()
{	
	cout << vec[0] << ", " << vec[1] << ": " << endl;
	double out[2] = {vec[0]+(vec[1]/vec[0]), vec[1]+(vec[0]/vec[1])};
	cout << out[0] << ", " << out[1] << endl;
	cout << endl;
}