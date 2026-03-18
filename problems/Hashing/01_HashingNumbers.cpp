//    Hashing -> 
// Given an array, we take input from user and tell how many time it present in the array

#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,1,3,2,1,3,5};
    int n = sizeof(arr)/sizeof(int);

    int hash[13] = {0};  // Here we took size = 13 bcs we are goona search for element greater than 13 if we gonna search for 18 then we took size 18
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    // these are the elements we seacrh for [1,4,2,3,12]
    int q;   // Enter 6 to search 5 elements

    cout<<"Enter q :"; 
    cin>> q;           
    while(--q){
        int number;
        cout<<">";
        cin>> number;

        cout<<"No of time present : "<<hash[number]<<endl;
    }
return 0;
}
