// Majority element means that elements occurs more than n/2 times in array

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int majorityElement(vector<int> &vec){
    map<int, int> mpp;
    for(int i=0; i<vec.size(); i++){
        mpp[vec[i]]++;        
    }

    for(auto it:mpp){
        if(it.second > (vec.size()/2)){
            return it.first;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {2,2,1,3,2,1,3,2,2};
    int ans = majorityElement(arr);
    if(ans == -1){
        cout<<"Not found!";
    }else{
        cout<<"Majority element : "<<ans;
    }
return 0;
}