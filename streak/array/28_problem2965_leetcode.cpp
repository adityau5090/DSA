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



int main() {

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> res = findMissingAndRepeatedValues(grid);
    cout<<"Repeated : "<<res[0]<<endl;    
    cout<<"Missing : "<<res[1];    

    return 0;
}