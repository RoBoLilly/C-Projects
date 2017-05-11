#include <iostream>
#include <vector>
using namespace std;

void printGrid(int grid[9][9]);
void createMap();
int blockSum(struct grid[9][9], int Block);
int rowSum(struct grid[9][9], int Row);
int columnSum(struct grid[9][9], int Column);


struct playfield{
    int number;
    int clueMap;
    int guessMap[9];
} grid[9][9];

int inputGrid[9][9] = {
    {2, 0, 0, 8, 0, 4, 0, 0, 6},
    {0, 0, 6, 0, 0, 0, 5, 0, 0},
    {0, 7, 4, 0, 0, 0, 9, 2, 0},
    {3, 0, 0, 0, 4, 0, 0, 0, 7},
    {0, 0, 0, 3, 0, 5, 0, 0, 0},
    {4, 0, 0, 0, 6, 0, 0, 0, 9},
    {0, 1, 9, 0, 0, 0, 7, 4, 0},
    {0, 0, 8, 0, 0, 0, 2, 0, 0},
    {5, 0, 0, 6, 0, 8, 0, 0, 1}
};

int main(){

    grid[0][0].guessMap[0] = 12;
    grid[0][0].guessMap[1] = 34;

    cout << grid[0][0].number << endl;
    cout << grid[0][0].guessMap[0] << endl;
    cout << "Sudoku" << endl;

    createMap();

    cout << grid[0][0].number << endl;
    printGrid(grid[][].numbers);
    //printGrid(clueMap);

    cout << endl;
}


int blockSum(struct grid[9][9], int Block){
    int BlockX;
    int BlockY;
    switch(Block){
        case 0:
            BlockX = 0;
            BlockY = 0;
            break;
        case 1:
            BlockX = 1;
            BlockY = 0;
            break;
        case 2:
            BlockX = 1;
            BlockY = 0;
            break;
        case 3:
            BlockX = 0;
            BlockY = 1;
            break;
        case 4:
            BlockX = 1;
            BlockY = 1;
            break;
        case 5:
            BlockX = 2;
            BlockY = 1;
            break;
        case 6:
            BlockX = 0;
            BlockY = 2;
            break;
        case 7:
            BlockX = 1;
            BlockY = 2;
            break;
        default:
            BlockX = 2;
            BlockY = 2;
            break;
        
    }
    int i = 0;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            i += grid[a+(BlockY*3)][b+(BlockX*3)].number;
        }
    }
    return i;
}

void createMap(){
    for(int a=0;a<9;a++){           // Creates ClueMap
        for(int b=0;b<9;b++){
            grid[a][b].number = inputGrid[a][b];
            if(grid[a][b].number > 0){
                grid[a][b].clueMap = 1;
            }else{
                grid[a][b].clueMap = 0;
            }
        }
    }
}

int rowSum(struct grid[9][9], int Row){
    int i = 0;
    for(int a=0;a<9;a++){
        i += grid[Row][a].number;
    }
    return i;
}

int columnSum(struct grid[9][9], int Column){
    int i = 0;
    for(int a=0;a<9;a++){
        i += grid[a][Column].number;
    }
    return i;
}

void printGrid(struct grid[9][9]){
    cout << "-------------------------------" << endl;
    for(int a=0;a<9;a++){
        static int i = 0;
        if(a == 3|| a == 6){
            cout << "-------------------------------" << endl;
        }
        cout << "|";
        for(int b=0;b<9;b++){
            if(b == 3||b==6){
                cout << "|";
            }
            if(grid[a][b].number == 0){
                cout << "   ";
            }else{
                cout << " " << grid[a][b].number << " ";
            }
            
        }
        cout << "|" << endl;
    }
    cout << "-------------------------------" << endl;
}