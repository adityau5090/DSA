// Find Missing And Repeated Values

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid){
    int n = grid.size();
    vector<int> freq(n*n+1, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            freq[grid[i][j]]++;
        }
    }
    int repeated = 0;
    int missing = 0;

    for(int i=1; i<=n*n; i++){
        if(freq[i] == 2) repeated = i;

        if(freq[i] == 0) missing = i;
    }
    
    return { repeated, missing};
}
// Tc -> O(n^2)    SC -> O(n^2)


vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
    int n = grid.size();
    int totalNumbers = n * n;
    int xorAll = 0;

    // XOR all grid values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            xorAll ^= grid[i][j];
        }
    }

    // XOR all expected values from 1 to n*n
    for (int i = 1; i <= totalNumbers; i++) {
        xorAll ^= i;
    }

    // Isolate the rightmost set bit
    int mask = xorAll & -xorAll;

    int firstGroup = 0, secondGroup = 0;

    // Divide grid values into two groups
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((grid[i][j] & mask) != 0) {
                firstGroup ^= grid[i][j];
            } else {
                secondGroup ^= grid[i][j];
            }
        }
    }

    // Divide expected values into two groups
    for (int i = 1; i <= totalNumbers; i++) {
        if ((i & mask) != 0) {
            firstGroup ^= i;
        } else {
            secondGroup ^= i;
        }
    }

    // Identify repeated and missing values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == firstGroup) {
                return {firstGroup, secondGroup};
            }
        }
    }

    return {secondGroup, firstGroup};
}
// TC -> O(n^2)



int main() {

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> res = findMissingAndRepeatedValues2(grid);
    cout<<"Repeated : "<<res[0]<<endl;    
    cout<<"Missing : "<<res[1];    

    return 0;
}