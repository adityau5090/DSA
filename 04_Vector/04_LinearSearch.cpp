#include<iostream>
#include<vector>
using namespace std;

int LinearSearch(vector<int> &vec,int target){
    for(int val : vec){
        if(val == target) return 1;
    }
    return 0;
}

int main(){
    vector<int>vec = {12,34,56,78,90,77,52};
    int target;
    cout<<"Enter the number, you want to search : ";
    cin>>target;
    int ans = LinearSearch(vec,target);
    if(ans == 1){
        cout<<"Number is present in the vector";
    }
    else{
        cout<<"The number is not present in vector";
    }
return 0;
}