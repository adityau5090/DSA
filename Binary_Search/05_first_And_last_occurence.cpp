#include<iostream>
#include<vector>
using namespace std;

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

pair<int, int> firstAndLAstOccurence(vector<int> &vec, int target){
  int lb = lowerBound(vec, target);
  if(lb == vec.size() || vec[lb] != target) return {-1, -1};
  return {lb, upperBound(vec, target) -1};
}
int main(){
  vector<int> vec = {1, 2, 2, 2, 3, 4, 5};

    int target = 2;

    pair<int, int> ans = firstAndLastOccurrence(vec, target);

    cout << "First occurrence: " << ans.first << endl;
    cout << "Last occurrence: " << ans.second << endl;
  return 0;
}
