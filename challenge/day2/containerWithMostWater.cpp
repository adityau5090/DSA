// Problem No 11 -> LeetCode


// Brute force approach

#include<iostream>
#include <vector>
using namespace std;
    int maxArea(vector<int>& h) {
        int ans = 0;

        for(int i=0; i<h.size()-1; i++){
            for(int j=i+1; j<h.size(); j++){
                int area = (j-i) * min(h[i], h[j]);
                ans = max(area, ans);
            }
        }
        return ans;
    }
int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};

    int ans = maxArea(arr);
    cout<<"Ans : "<<ans;
return 0;
}

