// Peak Index In Mountain Array

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////// Brute force Approach
int peakIndexInMountainArray(vector<int> &arr){
    int maxi = INT_MIN;
    int ind = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            ind = i;
        }
    }
    return ind;
}
// /// TC -> O(n) 

/////////////////////////////////////////////////  Binary Search Approach
int peakIndexInMountainArray2(vector<int> &arr){
    int low = 0, high = arr.size()-1;

    while(low < high){
        int mid = (low+high)/2;

        if(arr[mid] < arr[mid+1]) low = mid + 1;
        else high = mid; 
    }
    return low;
}
////// TC -> O(log(n))

int main() {

    vector<int> arr = {0,10,5,2};
    cout<<"Peak : "<<peakIndexInMountainArray2(arr);

    return 0;
}