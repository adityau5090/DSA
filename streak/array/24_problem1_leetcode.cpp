// Two Sum

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target){
    int n = arr.size();
    vector<int> res(2, -1);

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}
// TC -> O(n^2) 

////////////////////////////////////////////////////// Using hash map
vector<int> twoSum2(vector<int> &arr, int target){
    unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            int remaining = target - arr[i];

            if (mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }

            mp[arr[i]] = i;
        }

        return {};
}
//// TC -> O(n)    SC -> O(n)

int main() {

    vector<int> arr = {3,2,4};
    vector<int> res = twoSum(arr, 6);
    cout<<res[0]<<","<<res[1];

    return 0;
}