// Chai visuals DSA

// Valid Triangle Number     Leetcode No -> 611


// brute force approach 

#include<iostream>
#include<algorithm>
using namespace std;
    int noOfTriangle(int arr[], int n){
        int count = 0;
        sort(arr, arr+n);

        for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
            for(int k=j+1; k<n; k++)
            if(arr[i] + arr[j] > arr[k]){
                count++;
            }
        return count; 
    }
int main(){
    int arr[] = {2,3,4,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<noOfTriangle(arr, n);
return 0;
}
  

// Time complexity= O(n^3) | Space complexity= O(1)

// optimize approach

