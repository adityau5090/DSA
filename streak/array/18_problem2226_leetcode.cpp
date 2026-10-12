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



int main() {

    vector<int> candies = {5,8,6};
    cout<<"Maximum Children : "<<maximumCandies(candies, 3);

    return 0;
}