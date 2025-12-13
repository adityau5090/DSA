  //  Problem number -> 121 on Leetcode
 /* An array of prices were given, where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */

#include<iostream>
#include<climits>
using namespace std;

int maxProfitStock(int prices[], int n){
    int maxProfit = 0;
    int bestBuy = prices[0];
    for(int i=1; i<n; i++){
        if (prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy,prices[i]); 
    }
    return maxProfit;
}

int main(){
    int arr[]= {7,1,5,3,6,4};
    int n = sizeof(arr)/ sizeof(int); 
    int mp = maxProfitStock(arr,n);
    cout<<"Maximum Profit : "<<mp;
return 0;
}