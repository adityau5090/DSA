// Leetcode N0 -> 42


// Brute force approach --->
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int trapWater(vector<int> arr){
    int total = 0;

    for(int i = 0; i < arr.size() - 1; i++){
        int maxL = (i == 0) ? 0 : *max_element(arr.begin(), arr.begin() + i);
        int maxR = (i == arr.size() - 1) ? 0 : *max_element(arr.begin() + i + 1, arr.end());
        int cap = min(maxL, maxR);
        total += max(0, cap - arr[i]);
    }

    return total;
}

int main(){
    vector<int> arr = {4,2,0,3,2,5};
    cout<<trapWater(arr);
    
    return 0;
}