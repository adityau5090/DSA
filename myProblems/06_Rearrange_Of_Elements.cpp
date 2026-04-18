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

 
// second type in this no of -ve elements and no of +ve elements are not same so if any +ve or -ve number left then we have to add them at last without altering its order
 
void rearrange2(vector<int> &vec){
    vector<int> pos, neg;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] < 0) neg.push_back(vec[i]);
        else pos.push_back(vec[i]);
    }

    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            vec[2*i] = pos[i];
            vec[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        // start loop from remaining +ve elements in +ve array
        for(int i=neg.size(); i<pos.size(); i++){
            vec[index] = pos[i];
            index++;
        }
    }else{
        for(int i=0; i<pos.size(); i++){
            vec[2*i] = pos[i];
            vec[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i=pos.size(); i<neg.size(); i++){
            vec[index] = neg[i];
            index++;
        }
    }
} 
int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> arr2 = {1,2,-4,-5,3,6};
    // rearrange(arr);
    rearrange2(arr2);
    cout<<"Rearranged array: ";
    for(int i: arr2){
        cout<<i<<" ";
    }
return 0;
}