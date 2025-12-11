#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int product = 1;
    int size = sizeof(arr) / sizeof(int);
    for(int i=0; i<size; i++){
        product *= arr[i];
    }
    cout<<"Product of Numbers is : "<<product<<"\n";
return 0;
}