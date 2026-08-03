#include<iostream>
using namespace std;
    void insertionSort(int arr[], int n){
        for(int i=0; i<=n-1; i++){
            int j = i;
            while(j > 0 && arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
                j--;
            }
        }

    }
int main(){
    int arr[] = {23,4,5,7,28,14};
    int n = sizeof(arr)/ sizeof(arr[0]);
    insertionSort(arr, n);
    for(int it: arr){
        cout<<it<<",";
    }
return 0;
}

// Time complexity -> O(n^2) for all worst and average case but O(n) for best case