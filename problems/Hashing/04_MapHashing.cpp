/* In previous code of number hashing there aere two problem ->
 1. We have to check maximum no we have search to make an array of its size
 2. It can map only 10^6 data bcs int can only store that amount of data
 imagine we have a arr[200] and we have to only seacrh for [2,4,180] se we ended up making arr[180] elements so its memory wastage so here we use map<key,value>   */


#include<iostream>
#include<map>
using namespace std;

int main(){
    int arr[] = {1,2,4,14,20,14,11};
    int n = sizeof(arr)/sizeof(int);

    int q;
    cout<<"Enter q :";
    cin>>q;

    // pre-computing
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    while(q--){
        int number;
        cout<<">";
        cin>>number;
        // fetching
        cout<<"No of times present :"<<mpp[number]<<endl;
    }
return 0;
}