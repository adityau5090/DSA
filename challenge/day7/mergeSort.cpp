// Merge sort

#include<iostream>
#include<vector>
using namespace std;

    void merge(vector<int> &arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(low <= mid && right <= high){
            if(arr[low] <= arr[right]){
                temp.push_back(arr[low]);
                low++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(low <= mid){
            temp.push_back(arr[low]);
            low++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=0; i<temp.size(); i++){
            arr[left + i] = temp[i];
        }
    }
    void mergeSort(vector<int> &arr, int low, int high){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr,mid+1, high);
        merge(arr,low,mid,high);
    }
int main(){
    vector<int> arr = {2,7,8,45,13,5,9};
    mergeSort(arr, 0, arr.size()-1);
    for(int i: arr){
        cout<<i<<" ";
    }
return 0;
}

// time complexity = O(n.logn) for all case 
//  space complexity = O(n) 