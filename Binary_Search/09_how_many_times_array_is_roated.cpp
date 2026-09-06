#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int noOfrotation(vector<int> &arr){
  int low=0, high=arr.size()-1;
  int smallest = INT_MAX;
  int idx = -1;
  while(low<=high){
    int mid = low + (high-low)/2;
    
    if(arr[low] <= arr[mid]){
      if(arr[low] < smallest){
        smallest = arr[low];
        idx = low;
      }
      low = mid + 1;
    }else{
      if(arr[mid] < smallest){
        smallest = arr[mid];
        idx = mid;
      }
      high = mid -1;
    }
  }
return idx;
}

int main(){
  vector<int> arr = {3,4,5,1,2};
  cout<<noOfrotation(arr);
  return 0;
}
