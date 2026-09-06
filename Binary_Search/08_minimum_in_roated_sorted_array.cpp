#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minimum(vector<int> &arr){
  int low=0, high=arr.size()-1;
  int smallest = INT_MAX;
  while(low<=high){
    int mid = low + (high-low)/2;
    
    if(arr[low] <= arr[mid]){
      smallest = min(smallest, arr[low]);
      low = mid + 1;
    }else{
      smallest = min(smallest, arr[mid]);
      high = mid -1;
    }
  }
return smallest;
}

int main(){
  vector<int> arr = {3,4,5,1,2};
  cout<<minimum(arr);
  return 0;
}
