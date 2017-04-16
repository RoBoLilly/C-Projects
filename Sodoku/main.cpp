#include <iostream>
using namespace std;

void printGrid(int grid[9][9]);
//int blockSum(int grid[9][9], int BlockX, int BlockY);
int blockSum(int grid[9][9], int Block);
int rowSum(int grid[9][9], int Row);
int columnSum(int grid[9][9], int Column);
int usedNum(int grid[9][9], int x, int y, int outUsedNum[]);

int clueMap[9][9];
int grid[9][9] = {
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
    cout << "Sudoku" << endl;
    for(int a=0;a<9;a++){           // Creates ClueMap
        for(int b=0;b<9;b++){
            if(grid[a][b] > 0){
                clueMap[a][b] = 1;
            }else{
                clueMap[a][b] = 0;
            }
        }
    }
    
    printGrid(grid);

    //printGrid(clueMap);
    int usedNum[27];
    int i = 0;
    for(int a=0;a<9;a++){
        if(grid[0][a]>0){
            usedNum[i] = grid[0][a];
            i++;
        }
    }
    for(int b=0;b<9;b++){
        if(grid[b][0]>0){
            usedNum[i] = grid[b][0];
            i++;
        }
    }
    i = 0;
    for(int k=0;k<27;k++){
        cout << usedNum[k] <<  ", " << endl;
    }

    cout <<endl;
    return 0;
}

int usedNum(int grid[9][9], int x, int y, int outUsedNum[27]){
    return 0;
}

/*
int blockSum(int grid[9][9], int BlockX, int BlockY){
    if(BlockX > 2){
        BlockX = 2;
    }
    if(BlockY > 2){
        BlockY = 2;
    }
    int i = 0;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            i += grid[a+(BlockY*3)][b+(BlockX*3)];
            //cout << grid[a+(BlockY*3)][b+(BlockX*3)] << endl;
        }
    }
    return i;
} */

int blockSum(int grid[9][9], int Block){
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
            i += grid[a+(BlockY*3)][b+(BlockX*3)];
        }
    }
    return i;
}

int rowSum(int grid[9][9], int Row){
    int i = 0;
    for(int a=0;a<9;a++){
        i += grid[Row][a];
    }
    return i;
}

int columnSum(int grid[9][9], int Column){
    int i = 0;
    for(int a=0;a<9;a++){
        i += grid[a][Column];
    }
    return i;
}

void printGrid(int grid[9][9]){
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
            if(grid[a][b] == 0){
                cout << "   ";
            }else{
                cout << " " << grid[a][b] << " ";
            }
            
        }
        cout << "|" << endl;
    }
    cout << "-------------------------------" << endl;
}