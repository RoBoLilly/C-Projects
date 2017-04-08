#include<iostream>
using namespace std;

int add(int intA, int intB);
void printBook( struct Books book );
int n = 4; // number of books - 1
int m;

struct Books{
	char title[50];
	char author[50];
	int book_id;
};

int main(){

	struct Books Book1;
    struct Books Book2; 
    

    for(int a=0; a>15; a++){
    static int b = 0;
    	
    	if(b==0){
    		strcpy( Book2.title, "Telecom Billing");
    		strcpy( Book2.author, "Yakit Singha");
    		Book2.book_id = a + 1;
    	}
    	if(b==1){
			strcpy( Book1.title, "Learn C++ Programming");
   			strcpy( Book1.author, "Chand Miyan"); 
   			Book1.book_id = a + 1;
   		}
   		if(b==2){
   			strcpy( Book1.title, "Learn C++ Programming");
   			strcpy( Book1.author, "Chand Miyan"); 
   			Book1.book_id = a + 1;
   		}
   		if(b==3){
   			strcpy( Book1.title, "Learn C++ Programming");
   			strcpy( Book1.author, "Chand Miyan"); 
   			Book1.book_id = a + 1;
   		}
   		if(b==4){
   			strcpy( Book1.title, "Learn C++ Programming");
   			strcpy( Book1.author, "Chand Miyan"); 
   			Book1.book_id = a + 1;
   		}
   		
   		b++;
   		if(b>n){
   			b=0;
   		}
   		
   		
    }
    
	//cin >> n;
	//cin >> m;

	
	//cout << add(n,m) << endl; 

}

int add(int intA, int intB){
	return intA + intB;
}

void printBook( struct Books book ) {
   cout << "Book title : " << book.title <<endl;
   cout << "Book author : " << book.author <<endl;
   cout << "Book id : " << book.book_id <<endl;
}