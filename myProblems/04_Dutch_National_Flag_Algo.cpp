// Sort an array of 0's, 1's and 2's
// Ex -> [0,1,2,0,1,2,1,2,0,0,0,1]
// The approach is first we iterate the entire array and count all 0's, 1's and 2's and the we run three different loops and modify array

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(vector<int> &vec){
    int count0=0,count1=0, count2=0;

    // This take O(n)
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == 0) count0++;
        else if(vec[i] == 1) count1++;
        else count2++;
    }

    // These all three combines take O(n)
    for(int i=0; i<count0; i++){
        vec[i] = 0;
    }
    for(int i=count0; i<count0+count1; i++){
        vec[i] = 1;
    }
    for(int i=count0+count1; i<vec.size(); i++){
        vec[i] = 2;
    }

    // so overall TC = O(2n) => O(n) and SC = O(1)
}

 // Dutch National Flag algorithm  ( more optimal approach )
void dutchAlgo(vector<int> &vec){
    int low=0, mid=0, high=vec.size()-1;

    while(mid <= high){
        if(vec[mid] == 0){
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if(vec[mid] == 1){
            mid++;
        }
        else{
            swap(vec[mid], vec[high]); 
            high--;
        }
    }
}
// Time complexity = O(n) and SC = O(1)
int main(){
    vector<int> vec = {0,1,2,0,1,2,1,2,0,0,0,1};
    dutchAlgo(vec);

    for(int i : vec){
        cout<<i<<" ";
    }
return 0;
}