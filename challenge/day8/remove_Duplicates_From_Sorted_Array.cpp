// given arrray should be sorted
// Ex -> [1,1,2,2,2,3,3,3,3,4] => [1,2,3,4]

#include<iostream>
#include<vector>
#include<set>
using namespace std;

    // brute force approach
    // time coplexity = O(n.logn) for set
    vector<int> fun(vector<int> arr){
        set<int> s;
        vector<int> res;
        for(int i=0; i<arr.size(); i++){
            s.insert(arr[i]);
        }
        for(auto it: s){
            res.push_back(it);            
        }
        return res;
    }

    // optimal approach
    // time complexity = O(n)
    int fun2(vector<int>& arr){
        int i=0;
        for(int j=1; j<arr.size(); j++){
            if(arr[j] != arr[i]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }
int main(){
    vector<int> arr = {1,1,2,2,3,3,3,4,5,5};
    // vector<int> res= fun(arr);
    // for(int i: res){
    //     cout<<i<<" ";
    // }
    int new_size = fun2(arr);
    for(int i=0; i<new_size; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}