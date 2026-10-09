// /////// Relative Ranks

#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
        int n =score.size();
        vector<string> ans(n);
        vector<pair<int,int>> athelete;
        for(int i=0; i<n; i++){
            athelete.push_back({score[i], i});
        }
        sort(athelete.rbegin(), athelete.rend());

        for(int i=0; i<n; i++){
            int origionalIndex = athelete[i].second;

            if (i==0) ans[origionalIndex] = "Gold Medal";
            else if(i==1) ans[origionalIndex] = "Silver Medal";
            else if (i==2) ans[origionalIndex] = "Bronze Medal";
            else {
                ans[origionalIndex] = to_string(i+1);
            } 
        };
        return ans;
}
//////// TC -> O(nlogn)     SC -> O(n)

int main() {

    vector<int> arr = {10,3,8,9,4};
    vector<string> res = findRelativeRanks(arr);
    for(string i: res){
        cout<<i<<",";
    }

    return 0;
}