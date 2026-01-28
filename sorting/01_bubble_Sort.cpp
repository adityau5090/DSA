#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr.size()-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {34,56,20,43,10};
    cout<<"Unsorted array: ";
    for(int i: arr){
        cout<<i<<",";
    }
    cout<<"\n";
    bubbleSort(arr);
    cout<<"Sorted array: ";
    for(int i: arr){
        cout<<i<<",";
    }
}