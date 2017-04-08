#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define MAGENTA "\033[35m"      /* Magenta */
string RGB[] = {"\033[31m", "\033[32m", "\033[34m"};

static int cR = 0;
int cRit();

//cout << "" << endl; -- Copy

string group[] = {"Tryptamines", "Lysergamides", "Phenethylamines", "Entactogens"}; 
 
int main () {
cout << endl;
cout << "Enter the index number of the group of chemicals to search; Then press ENTER" << endl;
for(int a = 0; a < sizeof(group)/sizeof(*group); a++){
	cout << WHITE << a+1 << ": " << RGB[cR] << group[a] << RESET << endl ;cRit();
}

int a;
cin >> a;
if (a <= sizeof(group)/sizeof(*group)){
cout << group[a-1] << " were your selection" << endl;

}else{
cout << "The number you entered was not valid." << endl;
}

}


int cRit (){
if (cR <= 2){cR++;}
if (cR >= 3){cR = 0;}
return 0;
}