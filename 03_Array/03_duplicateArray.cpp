// Duplicate number in array

#include<iostream>
using namespace std;
int duplicate(int arr[],int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j])
            return arr[i];
        }
    }
    return -1;
}
int main(){
    int arr[] = {23,45,67,78,90,65,59,45};
    int size = sizeof(arr)/sizeof(int);
    int ans = duplicate(arr,size);
   if(ans == -1){
    cout<<"Not found any duplicate element!";
   }else{
    cout<<"Found duplicate element : "<<ans;
   }
return 0;
}