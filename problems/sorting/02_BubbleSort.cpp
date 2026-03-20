#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    for(int i=arr.size()-1; i>=0; i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    vector<int> arr = {13, 46, 24, 53, 20, 9};
    bubbleSort(arr);
    cout<<"Sorted array : ";
    for(int i: arr){
        cout<< i<<" ";
    }
    cout<<"\n";
return 0;
}