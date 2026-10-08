///// Island Paramemter

#include <bits/stdc++.h>
using namespace std;

int islandParameter(vector<vector<int>> & grid){
    int perimeter = 0;
    int row = grid.size();
    int column = grid[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(grid[i][j] == 1){
                
                //check upperside
                if(i == 0 || grid[i-1][j] == 0) perimeter++;
                // check lowerside
                if(i == row-1 || grid[i+1][j] == 0) perimeter++;
                // check leftside
                if(j == 0 || grid[i][j-1] == 0) perimeter++;
                //check rightside
                if(j == column-1 || grid[i][j+1] == 0) perimeter++;
            }
        }
    }
    return perimeter;
}
///// TC -> O(n^2)

int main() {

    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<"Perimeter : "<<islandParameter(grid);

    return 0;
}