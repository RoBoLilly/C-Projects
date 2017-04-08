#include <string>
using namespace std;

static int i = 0; // Number the id system starts from

class Puzzle {
	
	private:
    string  name;
    string  type;
    string  size;
    int   quality; // Scale From 0 - 10;
    int   puzzle_id;
    
     public:
    Puzzle(){i++;
    		puzzle_id = i;
    } 
    void setName(string nm);
    void setType(string tp);
    void setSize(string sz);
    void setQuality(int ql);
    string getName();
    string getType();
    string getSize();
    int getQuality();
    int getPuzzle_id();
};