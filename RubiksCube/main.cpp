#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "Puzzle.h"
using namespace std;

void printPuzzle(struct Puzzle puz);
int Puzzle::puzzleCount = 0;

int main(){
	//cout << "Main" << endl;
	
	Puzzle Rubiks;
	Puzzle Zanchi;
	Puzzle Vcube;
	Puzzle GhostCube;
	Puzzle CurvyCopter;

	GhostCube.setName("GhostCube");
	GhostCube.setType("Scramble");
	GhostCube.setSize("3x3");
	GhostCube.setQuality(10);

	CurvyCopter.setName("CurvyCopter");
	CurvyCopter.setType("Edge-Turing");
	CurvyCopter.setSize("54mm");
	CurvyCopter.setQuality(8);
	
	Rubiks.setName("Rubiks");
	Rubiks.setType("Basic");
	Rubiks.setSize("3x3");
	Rubiks.setQuality(4);
	
	Zanchi.setName("Zanchi");
	Zanchi.setType("Basic");
	Zanchi.setSize("3x3");
	Zanchi.setQuality(8);
	
	Vcube.setName("Vcube");
	Vcube.setType("Basic");
	Vcube.setSize("4x4");
	Vcube.setQuality(2);
	
	cout << "Puzzle Database V.0.4" << endl;
	cout << "There are " << Puzzle::getCount() << " Puzzles recorded." << endl 
	<< "Enter desired entry name or Puzzle ID: ";
	string j;
	cin  >> j;
	cout << endl;
	if (j == Rubiks.getName()|| j == "1"){
		printPuzzle(Rubiks);
	}
	if (j == Zanchi.getName()|| j == "2"){
		printPuzzle(Zanchi);
	}
	if (j == Vcube.getName()|| j == "3"){
		printPuzzle(Vcube);
	}
	if (j == CurvyCopter.getName()|| j == "4"){
		printPuzzle(Zanchi);
	}
	if (j == GhostCube.getName()|| j == "5"){
		printPuzzle(Vcube);
	}
	//cout << j << endl;
	
	return 0;
}

void printPuzzle(struct Puzzle puz){
	cout << puz.getName() <<" Type: " << puz.getType() << endl;
	cout << puz.getName() <<" Puzzle_id: " <<  puz.getPuzzle_id() << endl;
	cout << puz.getName() <<" Size: " <<  puz.getSize() << endl;
	cout << puz.getName() <<" Quality: " <<  puz.getQuality() << endl;
	cout << endl;
	
}