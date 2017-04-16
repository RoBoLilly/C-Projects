#include "Puzzle.h"
#include <string>
using namespace std;

//int i = 0;

void Puzzle::setName(string nm) {
   	name = nm;
}
void Puzzle::setType(string tp) {
    type = tp;
}
void Puzzle::setSize(string sz) {
	size = sz;
}
void Puzzle::setQuality(int ql) {
	quality = ql; 
}
string Puzzle::getName() {
	return name; 
}
string Puzzle::getType() {
	return type;
}
string Puzzle::getSize() {
	return size;
}
int Puzzle::getQuality() {
	return quality;
}
int Puzzle::getPuzzle_id(){
	return puzzle_id;
}
int Puzzle::getCount(){
	return puzzleCount;
}
