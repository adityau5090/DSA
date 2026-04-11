/*
Given an array of integers nums, return the number of good pairs.
A pair (i,j) is called good if nums[i] == nums[j] && i<j. 

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: (0,3),(0,4),(2,5),(3,4)
*/

#include<iostream>
#include<vector>
using namespace std;

void goodPairs(vector<int>& nums){
    int count=0;
    for(int i=0; i<nums.size()-1; i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
                cout<<i<<","<<j<<"\n";
            }
        }
    }
    cout<<"Total number of pairs : "<<count<<"\n";
}
int main(){
    vector<int> nums = {1,2,3,1,1,3};
    goodPairs(nums);
}