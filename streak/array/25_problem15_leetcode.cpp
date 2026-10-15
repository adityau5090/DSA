//// Three sum

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr){
    set<vector<int>> s;
    int n=arr.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());

                    if(s.find(temp) == s.end()){
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
// TC -> O(n^3 * log(uniqueTriplets))       SC -> O(uniqueTriplets)

/////////////////////////////////////////// Using Hashing
vector<vector<int>> threeSum2(vector<int> &arr){
    set<vector<int>> s;
    int n=arr.size();

    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());

                s.insert(temp);
            } 
            hashset.insert(arr[j]);
            
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
// TC -> O(n^2 * log(M))      SC -> O(n) + O(uniqueTriplets)


///////////////////////////////////////////////// Optimal Approach
vector<vector<int>> threeSum3(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
 
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}
// TC -> O(nlog(n) + O(n^2))   SC -> O(uniqueTriplets)

int main() {

    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum3(arr);
    int row = res.size(); 
    int column = res[0].size();

    for(int i=0; i<row; i++){
        cout<<"[";
        for(int j=0; j<column; j++){
            cout<<res[i][j]<<",";
        }
        cout<<"]"<<endl;
    }

    return 0;
}