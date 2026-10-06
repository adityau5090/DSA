//////// Move Zeros

#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &arr){
    int i=0;
    
    for(int j=0; j<arr.size(); j++){
        if(arr[j] != 0){
            if(i != j){
                swap(arr[i], arr[j]);
            }
            i++;
        }
    }

}
int main() {

    vector<int> arr = {0,1,0,3,12};
    moveZeros(arr);
    for(int i: arr){
        cout<<i<<",";
    }    

    return 0;
}