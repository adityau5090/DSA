// You are given a sorted array arr of distinct values and a target value m. You need to search for the index of the target value in the array.

// If the value is present in the array, then return its index.

// If the value is not present, determine the index where it would be inserted in the array while maintaining the sorted order.


//  same as lower bound problem

#include<iostream>
#include<vector>
using namespace std;
    int insertPosition(vector<int> vec, int target){
        int low=0, high=vec.size()-1;
        int ans = vec.size();

        while(low <= high){
            int mid = low + (high-low)/2;

            if(vec[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
int main(){
    vector<int> vec = {1, 5, 7, 19, 23, 34, 89};
    cout<<insertPosition(vec, 7);  
    return 0;
return 0;
}