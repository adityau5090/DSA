//swap alternate array
#include<iostream>
using namespace std;
void swapAlternate(int arr[],int size){
    for(int i =0; i<size; i+=2){
        if(i+1<size){
            // int temp = arr[i];
            // arr[i] = arr[i+1];
            // arr[i+1] = temp;
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[6]= {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(int);
    swapAlternate(arr,size);
    
return 0;
}