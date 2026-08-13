// Brute force approach

// #include<iostream>
// using namespace std;
//     void leftRotate(int arr[], int n, int k){
//         k = k % n;

//         int temp[n];
//         for(int i=0; i<n; i++){
//             temp[i] = arr[i];
//         }
//         for(int i=k; i<n; i++){
//             arr[i-k] = arr[i];
//         }
//         for(int i=n-k; i<n; i++){
//             arr[i] = temp[i - (n-k)];
//         }
//     }
// int main(){
//     int arr[] = {1,2,3,4,5,6,7};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     leftRotate(arr,size, 3);
//     for(int i: arr){
//         cout<<i<<" ";
//     }
// return 0;
// }

// Time complexity -> O(k) + O(n-k) + O(k) = O(n+k)
// Space Complexity -> O(k)


///////////Optimal Approach

// In this i have to perform three reverse let's see example -
// arr = {1,2,3,4,5,6} and k=3
// so now first reverse arr to k-1 places so it becomes - {3,2,1,4,5,6}
// now reverse the remaining arr - {3,2,1,6,5,4}
// and reverse the whole array - {4,5,6,1,2,3} yeahhhh it's done

#include<iostream>
#include<algorithm>
using namespace std;
    void leftRotate(int arr[], int n, int k){
        k = k % n;
        if(k == 0) return;
       reverse(arr, arr+k);
       reverse(arr+k, arr+n);
       reverse(arr, arr+n);
    }
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    leftRotate(arr,size, 3);
    for(int i: arr){
        cout<<i<<" ";
    }
return 0;
}