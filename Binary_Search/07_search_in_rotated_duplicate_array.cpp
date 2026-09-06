#include<iostream>
#include<vector>
using namespace std;

int searchInRotatedDuplicateArray(vector<int> &arr,int target){
  int low=0, high=arr.size()-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(arr[mid] == target) return mid;
    if(arr[low] == arr[mid] && arr[mid] == arr[high]){
      low++; high--; continue;
    }
    
    if(arr[low] <= arr[mid]){
      if(arr[low] <= target && target < arr[mid])
        high = mid -1;
      else low = mid + 1;
    }else{
      if(target > arr[mid] && target <= arr[high])
        low= mid + 1;
      else high = mid -1;
    }
  }
return -1;
}
int main(){
  vector<int> arr = {4,5,6,7,0,1,2};
  cout<<searchInRotatedDuplicateArray(arr,0);
  return 0;
}
