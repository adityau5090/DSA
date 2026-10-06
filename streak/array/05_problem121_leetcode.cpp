/////// Best Time To Buy & Sell Stock

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////// Brute Force Approach
int maxProfit(vector<int> & prices){
    int maxProf = 0;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            int profit = prices[j] - prices[i];
            maxProf = max(maxProf, profit); 
        }

    }
    return maxProf;
}
// ////// TC -> O(n^2)

int maxProfitt(vector<int> &prices){
    int minPrice = INT_MIN;
    int maxProfit = 0;

    for(int price : prices){
        if(price < minPrice){
            minPrice = price;
        }else if(price - minPrice > maxProfit){
            maxProfit = price - minPrice;
        }
    }
    return maxProfit;
}
int main() {

    vector<int> prices = {7,1,5,3,6,4};
    cout<<"Max Profit : "<<maxProfit(prices);

    return 0;
}