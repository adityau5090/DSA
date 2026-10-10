///// Distribute Candies

#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candyType){
    int n =candyType.size();
    set<int> uniqueCandy;
    for(int i=0; i<n; i++){
        uniqueCandy.insert(candyType[i]);
    }

    return min((int)uniqueCandy.size(), n/2);
}
// TC -> O(n)    SC -> O(n)

int main() {

    vector<int> candies = {1,1,2,2,3,3};
    cout<<distributeCandies(candies);

    return 0;
}