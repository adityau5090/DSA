// Search In Roated Sorted Array

#include <bits/stdc++.h>
using namespace std;

// ////////////////   /////////////////  ///  Brute Force Approach
int search(vector<int> &arr, int target){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target) return i;
    }
    return -1;
}
///// TC -> O(n)

///////////////////////////////////////// Binary Search Approach
int search2(vector<int> &arr, int target){
    int low = 0, high = arr.size()-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] == target) return mid;
        else if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target < arr[mid]){
                high = mid -1;
            }else{
                low = mid +1;
            } 
        }
        else{
            if(arr[mid] < target && target <= arr[high]){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
    }
    return -1;
}
/////// Tc -> O(log(n))

int main() {

    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<"At index : "<<search2(arr, 0); 

    return 0;
}