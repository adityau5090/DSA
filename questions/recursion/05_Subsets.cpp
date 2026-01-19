// Problem No => 78 on Leetcode 

#include<iostream>
#include<vector>
using namespace std;

void helper(int ind, vector<int>& nums, vector<vector<int>>& res, vector<int>& curr){

    if(ind == nums.size()){
        res.push_back(curr);
        return;
    }
    //include
    curr.push_back(nums[ind]);
    helper(ind+1, nums, res, curr);
    curr.pop_back();
    //exclude
    helper(ind+1, nums, res, curr);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> curr;
    helper(0, nums, res, curr);
    return res; 
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(vector<int> subsets : ans){
        cout<<"[";
        for(int x : subsets){
            cout<<" "<<x<<" ";
        }
        cout<<"]\t";
    }
}

/*                                       call stack and back track diagram

  helper(0, [])
│
├── include 1 → helper(1, [1])
│   │
│   ├── include 2 → helper(2, [1,2])
│   │   │
│   │   ├── include 3 → helper(3, [1,2,3])  ✅ store
│   │   │   ↑ backtrack (remove 3) → [1,2]
│   │   │
│   │   └── exclude 3 → helper(3, [1,2])     ✅ store
│   │       ↑ backtrack → [1]
│   │
│   └── exclude 2 → helper(2, [1])
│       │
│       ├── include 3 → helper(3, [1,3])     ✅ store
│       │   ↑ backtrack → [1]
│       │
│       └── exclude 3 → helper(3, [1])       ✅ store
│           ↑ backtrack → []
│
└── exclude 1 → helper(1, [])
    │
    ├── include 2 → helper(2, [2])
    │   │
    │   ├── include 3 → helper(3, [2,3])     ✅ store
    │   │   ↑ backtrack → [2]
    │   │
    │   └── exclude 3 → helper(3, [2])       ✅ store
    │       ↑ backtrack → []
    │
    └── exclude 2 → helper(2, [])
        │
        ├── include 3 → helper(3, [3])       ✅ store
        │   ↑ backtrack → []
        │
        └── exclude 3 → helper(3, [])        ✅ store
*/