#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> vec, int target){
  int low=0, high=vec.size()-1;
  while(low <= high){
    int mid = low + (high-low)/2;
    if(vec[mid] == target) return mid;
    else if(vec[mid] > target) high = mid -1;
    else low = mid + 1;
  }
return -1;
}

int main(){
  vector<int> vec = {1,4,7,9,34,56};
  int res = bs(vec,9);
  if(res == -1) cout<<"Not found";
  else cout<<"Found at :"<<res<<endl;
return 0;
}
