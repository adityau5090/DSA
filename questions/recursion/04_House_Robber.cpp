// Problem No => 198 on Leetcode

// #include<iostream>
// #include<vector>
// using namespace std;

// int helper(vector<int>& amount,int ind){
//     if( ind >= amount.size()) return 0;
//     // rob the house at index 
//     int rob = amount[ind] + helper(amount, ind+2);

//     // don't rob at index
//     int dontrob = helper(amount, ind+1);

//     return max(rob, dontrob);
// }

// int rob(vector<int>& amount){
//     return helper(amount, 0);
// }

// int main(){
//     vector<int> amount = {2,7,9,3,1};
//     cout<<rob(amount);
// }

// Time Complexity = O(2^n)
// Space Complexity = O(n)


// Opposite approach previous one is going from 0 to n this is going from n to 0

#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int>& amount,int ind){
    if( ind < 0) return 0;

    // rob the house at index 
    int rob = amount[ind] + helper(amount, ind-2);

    // don't rob at index
    int dontrob = helper(amount, ind-1);

    return max(rob, dontrob);
}

int rob(vector<int>& amount){
    return helper(amount, amount.size()-1);
}

int main(){
    vector<int> amount = {2,7,9,3,1};
    cout<<"Maximum amount I got after robbing is : ";
    cout<<rob(amount);
}