//////  Majority Element

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>&arr){
    int majority = INT_MIN;
    for(int i=0; i<arr.size()-1; i++){
        int count = 0;
        for(int j=i; j<arr.size(); j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count >= arr.size()/2) return arr[i];
    }
    return -1;
}
////// TC -> O(n/^2)   SC -> O(1)

/////       /////////////////////////////// Boyer-Moore Voting Algorithm
// If an element occurs more than half the time, it cannot be completely cancelled out by all the other elements
int majorityElement2(vector<int>& arr){
    int candidate = arr[0];
    int count = 0;

    for(int i=0; i<arr.size(); i++){

        if(count == 0){
            candidate = arr[i];
        }
        if(arr[i] == candidate){
            count++;
        }else{
            count--;
        }
        
    }
    return candidate;
}

int main() {

    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout<<"Majority Element : "<<majorityElement2(arr);

    return 0;
}