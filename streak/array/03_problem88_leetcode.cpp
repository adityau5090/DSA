/////// Merge Sorted Array

#include <bits/stdc++.h>
using namespace std;

//////////// brute force approach
// void merge(vector<int> &arr1, int m, vector<int> &arr2, int n){
//     vector<int> temp;

//     int a=0, b=0;
      
//     while(a<m && b<n){
//         if(arr1[a] <= arr2[b]){
//             temp.push_back(arr1[a]);
//             a++;
//         }else{
//             temp.push_back(arr2[b]);
//             b++;
//         }
//     }

//     while(a<m){
//         temp.push_back(arr1[a]);
//         a++;
//     }
//     while(b<n){
//         temp.push_back(arr2[b]);
//         b++;
//     }

//     for(int i=0; i<m+n; i++){
//         arr1[i] = temp[i];
//     }
    
// }

// /////// TC -> O(m+n)   SC -> O(m+n)

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n){
    int i=m-1;
    int j=n-1;
    int k=arr1.size()-1;

    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[k--] = arr1[i--];
        }else{
            arr1[k--] = arr2[j--];
        }
    }
    while(j>= 0){
        arr1[k--] = arr2[j--];
    }
}
// /////// TC -> O(m+n)   SC -> O(1)


int main() {

    vector<int> arr1 = {2,4,6,0,0,0};
    int m = 3;
    vector<int> arr2 = {1,3,8};
    int n =3;

    merge(arr1,m,arr2,n);
    for(int i: arr1){
        cout<<i<<",";
    }
    return 0;
}