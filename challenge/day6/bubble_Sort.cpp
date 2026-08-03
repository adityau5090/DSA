#include<iostream>
using namespace std;
    void bubbleSort(int arr[], int n){
        for(int i=n-1; i>=0; i--){
            bool didSwap = false;
            for(int j=0; j<=i-1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    didSwap = true;
                } 
            }
            if(didSwap == false){
                break;
            }
        }

    }
int main(){
    int arr[] = {23,4,5,7,28,14};
    int n = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr, n);
    for(int it: arr){
        cout<<it<<",";
    }
return 0;
}

// Time complexity -> O(n^2) for all worst and average case but O(n) for best case