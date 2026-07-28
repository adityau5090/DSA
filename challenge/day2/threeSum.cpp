// Problem No 15 -> LeetCode

// Brute Force ->

#include<iostream>
#include<vector>
#include<set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> seen;

        
        int n = nums.size();
        if (n < 3) {
            return result;
        }
        for (int i = 0; i < n - 2; i++) {
            
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());

                        if (seen.find(triplet) == seen.end()) {
                            seen.insert(triplet);
                            result.push_back(triplet);
                        }
                    }
                }
            }
        }

        return result;
    }
int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(arr);

    for (const auto &triplet : res) {
    cout << "[ ";
    for (int num : triplet) {
        cout << num << " ";
    }
    cout << "]" << endl;
}
return 0;
}


// Optimize Approach -> 

// sort(nums.begin(), nums.end());

// for (int i = 0; i < n - 2; i++) {

//     if (i > 0 && nums[i] == nums[i - 1])
//         continue;

//     int left = i + 1;
//     int right = n - 1;

//     while (left < right) {

//         int sum = nums[i] + nums[left] + nums[right];

//         if (sum == 0) {

//             res.push_back({nums[i], nums[left], nums[right]});

//             while (left < right && nums[left] == nums[left + 1])
//                 left++;

//             while (left < right && nums[right] == nums[right - 1])
//                 right--;

//             left++;
//             right--;
//         }
//         else if (sum < 0) {
//             left++;
//         }
//         else {
//             right--;
//         }
//     }
// }