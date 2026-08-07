// quick sort

#include<iostream>
#include<vector>
using namespace std;

    int qs(vector<int> &arr, int low, int high){
        int pivot = arr[low];
        int i=low; int j=high;
        while(i<j){
            while(i <= high && arr[i] <= pivot){
                i++;
            }
            while(j >= low && arr[j] > pivot){
                j--;
            }
            if(i < j ){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
    void quickSort(vector<int> &arr,int low, int high){
        if(low < high){
            int partitionIdx = qs(arr, low, high);
            quickSort(arr, low, partitionIdx - 1);
            quickSort(arr, partitionIdx + 1, high);
        }
        
    }
int main(){
    vector<int> arr = {56,45,12,45,8,20,11};
    quickSort(arr, 0, arr.size()-1);
    for(int i :arr){
        cout<<i<<" ";
    }
return 0;
}

