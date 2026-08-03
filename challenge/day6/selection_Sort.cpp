#include<iostream>
using namespace std;
    void selectionSort(int arr[], int n){
        for(int i=0; i<n-1; i++){
            int mini = i;
            for(int j=i; j<n; j++){
                if(arr[j] < arr[mini]){
                    mini = j;
                } 
            }
            swap(arr[i], arr[mini]);
        }

    }
int main(){
    int arr[] = {23,4,5,7,28,14};
    int n = sizeof(arr)/ sizeof(arr[0]);
    selectionSort(arr, n);
    for(int it: arr){
        cout<<it<<",";
    }
return 0;
}

// Time complexity -> O(n^2) for all case 