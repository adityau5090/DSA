//       Problem number => 540 on Leetcode

#include<iostream>
#include<vector>
using namespace std;

int singleElememt(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    int st=0, end=n-1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(mid==0 && arr[mid] != arr[mid+1]) return arr[mid];
        if(mid==n-1 && arr[mid] != arr[mid-1]) return arr[mid];

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }else if(mid % 2 == 0){ // Left & Right even numbers
            if(arr[mid] == arr[mid-1]){ //left side
                end = mid-1;
            }else{  // Right side
              st = mid+1;  
            }
        }else{  // Left & Right odd numbers
            if(arr[mid] == arr[mid-1]){ // Right side
                st = mid+1;
            }else{ // Left side
                end = mid-1;
            }
        }

    }
    return -1;
}
int main(){
    vector<int> vec = {1,1,2,2,3,3,4,4,5,6,6};
    cout<<"Single element : "<<singleElememt(vec);
return 0;
}