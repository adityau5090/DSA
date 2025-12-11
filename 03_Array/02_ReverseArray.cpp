// Reverse an array without using any extra array
#include<iostream>
using namespace std;

//   two pointer approach
void reverseArray(int arr[],int size){
    int startindex = 0;
    int endindex = size-1;
    while(startindex < endindex){
        swap(arr[startindex],arr[endindex]);
        startindex++;
        endindex--;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
}
int main(){
    int arr[] = {1,3,5,7,9,11,13,15,17};
    int size = sizeof(arr) / sizeof(int);
    reverseArray(arr,size);
return 0;
}