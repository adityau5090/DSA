#include<iostream>
#include<vector>
using namespace std;

int bsRecursive(vector<int> vec,int high,int low, int target){
  if(high < low) return;
  int mid = (low + high)/2;
  if(vec[mid] == target) return mid;
  else if(vec[mid] > target){
    return bsRecursive(vec,mid -1,low,target);
  }
  else return bsRecursive(vec,high,mid+1,target);
return -1;
}

int main(){
  vector<int> vec = {1,4,7,9,34,56};
  int res = bsRecursive(vec, vec.size()-1, 0, 9);
  if(res == -1) cout<<"Not found";
  else cout<<"Found at :"<<res<<endl;
return 0;
}
