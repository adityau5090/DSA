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

    // time complexity = O(n) + O(logn)
    // space complexity = O(n)
}

// Moore's voting algorithm

int morresAlgo(vector<int> &vec){
    int count=0;
    int el;
    for(int i=0; i<vec.size(); i++){
        if(count == 0){
            count = 1;
            el=vec[i];
        }else if(vec[i] == el){
            count++;
        }else{
            count--;
        }
    }
    int count1 = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == el) count1++;
    }
    if(count1 > (vec.size()/2)){
        return el;
    }
    return -1;

    // time complexity = O(n)
    // space complexity = O(1)
}

int main(){
    vector<int> arr = {2,2,1,3,2,1,3,2,2};
    int ans = morresAlgo(arr);
    if(ans == -1){
        cout<<"Not found!";
    }else{
        cout<<"Majority element : "<<ans;
    }
return 0;
}