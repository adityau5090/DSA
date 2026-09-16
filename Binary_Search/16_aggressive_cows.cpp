#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool canWePlace(vector<int> & stalls, int dist, int cows){
  int countCows=1; int last = stalls[0];
  for(int i=1; i<stalls.size(); i++){
    if(stalls[i] - last >= dist) {
      countCows++;
      last = stalls[i];
    }
  }
  if(countCows >= cows) return true;
  else return false;
}

int aggressiveCows(vector<int>& stalls, int cows){
sort(stalls.begin(), stalls.end());
  int low = 0, high= stalls[stalls.size()-1] - stalls[0];
  while(low<=high){
    int mid = (low+ high)/2;
    if(canWePlace(stalls, mid, cows) == true){
      low = mid + 1;
    }else{
      high = mid -1;
    }
  }
  return high; 
}

int main(){
  vector<int> arr = {0,3,4,7,10,9};
  int cows = 4;
  cout<<aggressiveCows(arr, cows);
  return 0;
}
