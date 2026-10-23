// Delete Columns To Make Sorted

#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> & arr){
    int deleteCount = 0;

    for(int i=0; i<arr[0].size(); i++){
        for(int j=0; j<arr.size()-1; j++){
            if(arr[j][i] > arr[j+1][i]){
                deleteCount++;
                break;
            }
        }
    }
    return deleteCount;
}

int main() {

    vector<string> arr = {"abc", "bce", "cae"};
    cout<<minDeletionSize(arr);

    return 0;
}