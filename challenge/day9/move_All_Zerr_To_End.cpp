// Move all zero to the end of array
// arr= [1,2,0,4,6,0,7,0] => [1,2,4,6,7,0,0,0]


// brute force approach

// #include<iostream>
// using namespace std;
//     void moveToEND(int arr[], int n){
//         if(n==0) return;

//         int temp[n];
//         int j=0;
//         for(int i=0; i<n; i++){
//             if(arr[i] != 0){
//                 temp[j] = arr[i];
//                 j++;
//             }
//         }
//         for(int i=0; i<j; i++){
//             arr[i] = temp[i];
//         }
//         for(int i=j; i<n; i++){
//             arr[i] = 0;
//         }
//     }
// int main(){
//     int arr[] = {1,2,0,4,6,0,7,0};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     moveToEND(arr,size);
//     for(int it: arr){
//         cout<<it<<" ";
//     }
// return 0;
// }

// time complexity = O(n) + O(n-j) + O(j) = O(2n)
// space complexity = O(n)

////// Optimal solution -> use two pointer approach
#include<iostream>
using namespace std;
    void moveToEND(int arr[], int n){
        int j=-1;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;

        for(int i=j+1; i<n; i++){
            if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
int main(){
    int arr[] = {1,2,0,4,6,0,7,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    moveToEND(arr,size);
    for(int it: arr){
        cout<<it<<" ";
    }
return 0;
}

// time complexity = O(x) + (n-x) = O(n)
// space complexity = O(1)