// Maximum Candies Allocated To K Children

#include <bits/stdc++.h>
using namespace std;

////////// /////////////////////////////////////// Brute Force Appproach 
int maximumCandies(vector<int> &candies, long long k){

    int n = *max_element(candies.begin(), candies.end());

    for(int i=n; i>=1; i--){
        long long children = 0;

        for(int pile: candies){
            children += pile/i;
        }
        if(children >= k){
            return i;
        }
    }
    return 0;
}
// if n= no. of piles and m= size of largest pile then
//  TC -> O(mn) 

/////////////////////////////////////////// Binary Seacrh Approach
int maximumCandies2(vector<int> &candies, long long k){

    int low = 1;
    int high = *max_element(candies.begin(), candies.end());
    int ans = 0;

    while(low<=high){
        int mid = (low+high)/2;
        long long children = 0;

        for(int pile: candies){
            children += pile/mid;
        }
        if(children >= k){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return ans;
}

int main() {

    vector<int> candies = {5,8,6};
    cout<<"Maximum Children : "<<maximumCandies2(candies, 3);

    return 0;
}