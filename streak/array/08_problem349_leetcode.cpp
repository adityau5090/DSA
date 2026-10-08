//// Intersection of two arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &arr1, vector<int> &arr2){
    vector<int> res;

    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2.size(); j++){
            if(arr1[i] == arr2[j]){
                if(find(res.begin(), res.end(), arr1[i]) == res.end()){
                    res.push_back(arr1[i]);
                }
                break;
            }
        }
    }
    return res;
}
///////// TC -> O(n^2)  

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2) {
        if (set1.count(num)) {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}

// TC -> O(n)            SC -> O(n)

int main() {

    vector<int> a = {1,2,2,1};    
    vector<int> b = {2,2}; 
    vector<int> res = intersection2(a,b);
    for(int it: res){
        cout<<it<<",";
    }  

    return 0;
}