#include <iostream>

using namespace std;
int inst = 10;


class Cat {
   public:
   	double Xpos ,Ypos, Zpos;  
    
      void setXpos( double len );
      void setYpos( double bre );
      void setZpos( double hei );
      void addXpos( double inp);
      void addYpos( double inp);
      void addZpos( double inp); 
     
     
      void setXpos( double len ) {
  		 Xpos = len;
  	}
  	  
  	  void setYpos( double bre ) {
   		Ypos = bre;
	}

	void setZpos( double hei ) {
  		 Zpos = hei;
	}

	void addXpos( double inp ) {
		   Xpos += inp;
	}

	void addYpos( double inp ) {
   		Ypos += inp;
	}

	void addZpos( double inp ) {
   		Zpos += inp;
	}

};

// Member functions definitions


int main( ) {
   Cat cat1;        // Declare Cat1 of type Cat
   Cat cat2;        // Declare Cat2 of type Cat
   
	cat1.setXpos(5.0);
	cat1.setYpos(6.0);
	cat1.setZpos(7.0);
	
	cat2.setXpos(12.0);
	cat2.setYpos(-3.0);
	cat2.setZpos(8.0);


   
   for(int a=0;a<inst;a++){
   		cat1.addXpos(2.0);
   		cat1.addYpos(-4.2);
   		cat1.addZpos(6.0);
   		
   		cat2.addXpos(-4.0);
   		cat2.addYpos(2);
   		cat2.addZpos(3.6);
   		
   		cout << endl << endl;
   		
   		cout << "Xpos for Cat" << 1 << ": " << cat1.Xpos << endl;
   		cout << "Ypos for Cat" << 1 << ": " << cat1.Ypos << endl;
   		cout << "Zpos for Cat" << 1 << ": " << cat1.Zpos << endl;
   		cout << endl;
   		cout << "Xpos for Cat" << 2 << ": " << cat2.Xpos << endl;
   		cout << "Ypos for Cat" << 2 << ": " << cat2.Ypos << endl;
   		cout << "Zpos for Cat" << 2 << ": " << cat2.Zpos << endl;
   }
   return 0;
}







