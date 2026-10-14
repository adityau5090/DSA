// Subarray Sum Equals K

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k){
    int n=arr.size();
    int count = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k) count++;
        }
        
    }
    return count;
}
//// TC -> O(n^2)  SC -> O(1)

//////////////////////////////////////// From ChatGpt (Not understand)
int subarraySum2(vector<int>& arr, int k) {
    unordered_map<int, int> mp;

    mp[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int num : arr) {
        prefixSum += num;

        int remaining = prefixSum - k;

        if (mp.find(remaining) != mp.end()) {
            count += mp[remaining];
        }

        mp[prefixSum]++;
    }

    return count;
}

int main() {

    vector<int> arr = {1,1,1};
    cout<<"No of subarraySum : "<<subarraySum2(arr, 2);

    return 0;
}