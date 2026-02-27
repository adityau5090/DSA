#include<iostream>

using namespace std;

bool jump(int arr[],int n){
    int max_jump = 0;
    for(int i=0; i<n; i++){
        if(i > max_jump) return false;
        max_jump = max(max_jump, i + arr[i]);
    }
    return true;
}

int main(){
    int arr[] = {2,3,1,0,4};
    int size = sizeof(arr)/sizeof(int);

    cout<<jump(arr,size);
    
return 0;
}