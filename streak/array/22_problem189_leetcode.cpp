/// Rotate Array

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int k){
    int n = arr.size();
    k = k % n;

    vector<int> res;

    for (int i = n - k; i < n; i++) {
        res.push_back(arr[i]);
    }

    for (int i = 0; i < n - k; i++) {
        res.push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = res[i];
    }
}
// TC -> O(n)  SC -> O(n)

/////////////////////////////////////////// Optimal Approach
void rotate2(vector<int> &arr, int k){
    int n = arr.size();
    k = k % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
///// TC -> O(n)   SC -> O(1)

int main() {

    vector<int> arr = {1,2,3,4,5,6,7};    
    rotate2(arr, 3);

    for(int it: arr){
        cout<<it<<",";
    }

    return 0;
}