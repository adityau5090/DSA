// Pascal's Triangle

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows){
    
    vector<vector<int>> ans;
    for(int i=0; i<numRows; i++){
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++){
            row[j] = ans[i-1][j -1] + ans[i-1][j];
        }
        ans.push_back(row); 
    }
    return ans;
}
int main() {

    vector<vector<int>> res = generatePascalTriangle(5);
    
    for(int i=0; i<res.size(); i++){
        cout<<"[";
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<",";
        }
        cout<<"]"<<endl;
    }

    return 0;
}