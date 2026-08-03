// in integer hashing we got a problem that we can't go more than 10^6 that were c++ STL comes in picture, we are gonna use map for that shit -> map<key, value>
// here key means actual_value and value means its frequency

#include<iostream>
#include<vector>
#include<map>
using namespace std;
    int hashMap(vector<int> arr, int target){
        map<int, int> mpp;
        for(int i=0; i<arr.size(); i++){
            mpp[arr[i]]++;
        }
        // for(auto it : mpp){
        //     cout<<it.first<<","<<it.second<<endl;
        // }
        return mpp[target];
    }
int main(){
    vector<int> arr = {1,2,3,1,2,1,12};
    cout<<hashMap(arr, 2);
return 0;
}

// benefits of using map that we only store value that needed but in array we have to store all those too which are not present 

// time complexity

//     storing and fetching in all cases from map takes -> log(n) time


// we can use unorderred_map here because its timw coplexity is O(1) for best and average case only in worst case it gives time complexity of O(n)