#include<iostream>
#include<climits>
using namespace std;
    int largestEle(int arr[], int size){
        int largest = INT_MIN;
        for(int i = 0; i < size; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        return largest;
    }
int main(){
    int arr[] = {23,4,53,66,7};
    int size = sizeof(arr)/ sizeof(arr[0]);
    cout<<largestEle(arr, size);
return 0;
}