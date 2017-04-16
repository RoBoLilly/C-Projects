#include <string>
using namespace std;

class Puzzle {
	
	private:
    string  name;
    string  type;
    string  size;
    int   quality; // Scale From 0 - 10;
    int   puzzle_id;
    
    public:
    static int puzzleCount;
    Puzzle(){
            puzzleCount++;
    		puzzle_id = puzzleCount;
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
    static int getCount();
};