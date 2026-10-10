/// Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////  Brute force approach
int maxSubarraySum(vector<int> &arr){
    int maxSum = arr[0];
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxSum = max(maxSum, sum); 
        }
    }
    return maxSum;
}
// // TC -> O(n^2)   Sc -> O(1)

/////////////////////////////////////////   Kadane's Algorith,
int maxSubarraySum2(vector<int> &arr){
    int maxSum = arr[0];
    int currentSum = 0;
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum); 
        if(currentSum < 0) currentSum = 0;
    }
    return maxSum;
}
///////// TC -> O(n)    SC -> O(1) 

int main() {

    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Max subarray sum : "<<maxSubarraySum2(arr);

    return 0;
}