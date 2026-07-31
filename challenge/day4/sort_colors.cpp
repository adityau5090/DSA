// Leetcode No -> 75

// Brute force approach

// #include<iostream>
// #include<vector>
// using namespace std;
//     void sortColors(vector<int> &arr){
//         int red=0,white=0,blue=0;

//         for(int i=0; i<arr.size(); i++){
//             if(arr[i] == 0) red++;
//             else if(arr[i] == 1) white++;
//             else blue++;
//         }

//         for(int i=0; i<arr.size(); i++){
//             if(i < red) arr[i]=0;
//             else if(i < red + white) arr[i] = 1;
//             else arr[i] = 2;
//         }
//     }
// int main(){
//     vector<int> arr = {2,0,1,0,1,2,0};
//     sortColors(arr);
//     for(int i : arr){
//         cout<<i<<"\t";
//     }
// return 0;
// }

// better approach

#include<iostream>
#include<vector>
using namespace std;

    void sortColors(vector<int> &arr){
        int front=0;
        int back = arr.size()-1;

        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0){
                swap(arr[i], arr[front]);
                front++;
            }
        }

        for(int i=arr.size()-1; i>=front; i--){
            if(arr[i] == 2){
                swap(arr[i], arr[back]);
                back--;
            }
        }
    }
int main(){
    vector<int> arr = {2,0,1,0,1,2,0};
    sortColors(arr);
    for(int i : arr){
        cout<<i<<"\t";
    }
return 0;
}