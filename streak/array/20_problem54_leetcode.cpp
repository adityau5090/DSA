//// Spiral Matrix

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){

    vector<int> result;
    int topRow = 0;
    int bottomRow = matrix.size()-1;
    int leftColumn = 0;
    int rightColumn = matrix[0].size()-1;

    while(topRow <= bottomRow && leftColumn <= rightColumn){
        // 1. Move To Right
        for(int col=leftColumn; col<= rightColumn; col++){
            result.push_back(matrix[topRow][col]);
        }
        topRow++;

        // 2. Move To Down
        for(int row=topRow; row<=bottomRow; row++){
            result.push_back(matrix[row][rightColumn]);
        }
        rightColumn--;

        // 3. Move To Left
        if(topRow <= bottomRow){
            for(int col=rightColumn; col>=leftColumn; col--){
                result.push_back(matrix[bottomRow][col]);
            }
            bottomRow--;
        }

        // 4. Move To Up
        if(leftColumn <= rightColumn){
            for(int row=bottomRow; row>=topRow; row--){
                result.push_back(matrix[row][leftColumn]);
            }
            leftColumn++; 
        }
    }
    return result;
}

int main() {

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(matrix);
    for(int it: res){
        cout<<it<<",";
    }

    return 0;
}