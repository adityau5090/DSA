/// Product Of Array Expect Self

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////   Brute Force Approach
vector<int> productExceptSelf(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        int prod = 1;
        for(int j=0; j<n; j++){
            if(j == i) continue;
            prod *= arr[j]; 
        }
        ans.push_back(prod);

    }
    return ans;
}
// TC -> (n^2)


vector<int> productExceptSelf2(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n,1);
    
    ////////////////  This work only for non-zero elements
    // int prod = 1;
    // for(int i=0; i<n; i++){
    //     prod *= arr[i]; 
    // }
    // for(int i=0; i<n; i++){
    //     ans[i] = prod/arr[i];
    // }

    //Prefix -> Product of all elements to the left of the current index.
    //Suffix -> Product of all elements to the right of the current index.

    int prefix = 1; 
    for(int i=0; i<n; i++){
        ans[i] *= prefix;
        prefix *= arr[i];
    }

    int suffix = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] *= suffix;
        suffix *= arr[i];
    }

    return ans;
}
///// TC -> O(n)   SC => O(1)

int main() {

    vector<int> arr = {1,2,3,4};
    vector<int> result = productExceptSelf2(arr);
    for(int it: result){
        cout<<it<<",";
    }

    return 0;
}