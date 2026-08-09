// Leetcode no => 1
// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// brote force approach
// Time copmlexity = O(n^2)
vector<int> twoSum(vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if ((arr[i] + arr[j]) == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> twoSum2(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];

        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }

        mp[arr[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    vector<int> res = twoSum2(arr, 13);
    cout << res[0] << "," << res[1];
    return 0;
}