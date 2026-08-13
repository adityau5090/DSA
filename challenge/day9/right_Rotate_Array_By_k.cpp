#include<iostream>
using namespace std;
    int rightRotate(int arr[], int n, int k){
        k= k % n;
        int temp[k];
        // store the last k elements 
        for(int i=0; i<k; i++){
            temp[i] = arr[n-k+i];
        }
        // shift the remaining elements to right
        for(int i=n-1; i>= k; i--){
            arr[i] = arr[i - k];
        }
        // put the store element at beginning
        for(int i=0; i<k; i++){
            arr[i] = temp[i];
        }
    }
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    rightRotate(arr, size, 3);
    for(int i: arr){
        cout<<i<<" ";
    }
return 0;
}