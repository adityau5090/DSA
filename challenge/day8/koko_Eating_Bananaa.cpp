#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1; // minimum hour it take
    int high = *max_element(piles.begin(), piles.end());  // maximum hour it take
    int ans = high;

    while(low <= high){
        int mid = (low+high)/2;
        long hours = 0;
        for(int pile : piles){
            hours += (pile + mid - 1) / mid;
        }
        if(hours <= h){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
    
}
int main()
{
    vector<int> arr = {3, 6, 7, 11};
    cout<<minEatingSpeed(arr, 8);
    return 0;
}