// Rearrange of elements by sign
// We have give an array with equal negative elements and equal positive elements
// That means if n elements are given then thre are n/2 psoitive and n/2 negative elements and n will be always be an even number 
// now we have rearrange them in an alternate order means first positive and second negative, but their order should be same 
//Ex -> [3,1,-2,-5,2,-4]  
//      [3,-2,1,-5,2,-4]  

#include<iostream>
#include<vector>
using namespace std;

void rearrange(vector<int> &vec){
    vector<int> positiveEle;
    vector<int> negativeEle;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] < 0) negativeEle.push_back(vec[i]);
        else positiveEle.push_back(vec[i]);
    }

    for(int i=0; i<vec.size()/2; i++){
        vec[2*i] = positiveEle[i];
        vec[2*i+1] = negativeEle[i];
    }

    // Time complexity -> O(n) + O(n)
    // Space complexity -> O(n)   (because we take n/2 space for +ve and n/2 for -ve)
}
int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    rearrange(arr);
    cout<<"Rearranged array: ";
    for(int i: arr){
        cout<<i<<" ";
    }
return 0;
}