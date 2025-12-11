#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {34,45,67,89,20,16,77,69};
    int size = sizeof(arr) / sizeof(int);
    int target = 77;
    int ans = linearSearch(arr,size,target);
    if(ans != -1){
        cout<<"Target is found at index "<<ans<<"\n";
    }
    else{
        cout<<"Target is not found";
    }
return 0;
}