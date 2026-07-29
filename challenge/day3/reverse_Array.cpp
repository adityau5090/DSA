// two pointer recursion 

// #include<iostream>
// #include<algorithm>

// using namespace std;

//     void swapArr(int arr[], int left, int right){
//         if(left >= right) return;

//         swap(arr[left], arr[right]);

//         swapArr(arr, left+1, right-1);
//     }
// int main(){
//     int arr[] = {1,2,3,4,5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     swapArr(arr, 0, size-1);

//     for(int i=0;i<size;i++) cout<<arr[i]<<" ";
//     cout<<"\n";

//     return 0;
// }

// let's try with one pointer
// -> (i, n-i-1) always give opposite value

#include<iostream>
using namespace std;
    void swapArr(int arr[],int size, int i){

        if(i>= size/2) return;

        swap(arr[i], arr[size-i-1]);

        swapArr(arr,size, i+1);

    }
int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    swapArr(arr,size, 0);

    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
    cout<<"\n";
return 0;
}