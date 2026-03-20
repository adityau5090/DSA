#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        int minimum =  i;
        for(int j=i; j<arr.size(); j++){
            if(arr[j] < arr[minimum]){
                minimum = j;
            }
            int temp = arr[minimum];
            arr[minimum] = arr[i];
            arr[i] = temp;
        } 
    }
}
int main(){
    vector<int> arr = {13, 46, 24, 53, 20, 9};
    selectionSort(arr);
    cout<<"Sorted array : ";
    for(int i: arr){
        cout<< i<<" ";
    }
    cout<<"\n";
return 0;
}