#include<iostream>
#include<vector>
using namespace std;
// Lower bound -> smallest index such that arr[ind] >= x
// Upper bound -> smallest index such that arr[ind] > x

int lowerBound(vector<int> &vec, int target){
  int low = 0, high = vec.size()-1;  
  int ans = vec.size();
  while(low<=high){
    int mid = (low+high)/2;
    if(vec[mid] >= target){
      ans = mid;
      high = mid -1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}
int upperBound(vector<int> &vec, int target){
  int low = 0, high = vec.size()-1;  
  int ans = vec.size();
  while(low<=high){
    int mid = (low+high)/2;
    if(vec[mid] > target){
      ans = mid;
      high = mid -1;
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}

int main(){
  vector<int> vec = {1,4,7,9,34,56};
  cout<<"Lower Bound : "<<lowerBound(vec,9)<<endl;
  cout<<"Upper Bound : "<<upperBound(vec,9)<<endl;
return 0;
}
