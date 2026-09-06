#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//floor -> largest number in array <= x
// ceil -> smallest number in array >= x

int floor(vector<int> &vec, int target){
  int low = 0, high = vec.size()-1;  
  int ans = INT_MIN;
  while(low <= high){
    int mid = (low+high)/2;
    if(vec[mid] <= target){
      ans = vec[mid];
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return ans;
}
int ceil(vector<int> &vec, int target){
  int low = 0, high = vec.size()-1;  
  int ans = INT_MAX;
  while(low <= high){
    int mid = (low+high)/2;
    if(vec[mid] >= target){
      ans = vec[mid];
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
  cout<<"Floor : "<<floor(vec,9)<<endl;
  cout<<"Ceil : "<<ceil(vec,9)<<endl;
return 0;
}
