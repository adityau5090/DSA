// Problem No => 746 on Leetcode

#include<iostream>
#include<vector>
using namespace std;

int recursiveFun(vector<int>& cost, int ind){
    if(ind >= cost.size()) return 0;
    
    return cost[ind] + min(recursiveFun(cost,ind+1),recursiveFun(cost,ind+2));
}
int minCostClimbingStairs(vector<int>& cost){
    return min(recursiveFun(cost,0),recursiveFun(cost,1));
}

int main(){
    vector<int> cost = {10,15,20};
    cout<<"Minimum cost of climbing stairs : ";
    cout<<minCostClimbingStairs(cost);
}


// Opposite approach 

// int recursiveFun(vector<int>& cost, int ind){
//     if(ind < 0) return 0;
    
//     return cost[ind] + min(recursiveFun(cost,ind-1),recursiveFun(cost,ind-2));
// }
// int minCostClimbingStairs(vector<int>& cost){
//     return min(recursiveFun(cost,cost.size()-1),recursiveFun(cost,cost.size()-2));
// }

// int main(){
//     vector<int> cost = {10,15,20};
//     cout<<"Minimum cost of climbing stairs : ";
//     cout<<minCostClimbingStairs(cost);
// }