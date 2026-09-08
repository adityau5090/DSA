#include <iostream>
#include <vector>
#include <cmath> 
#include <climits> 
#include <algorithm>
using namespace std;

int totlaHour(vector<int>&arr, int hourly){
  int totalHours = 0;  
  for(int i=0; i<arr.size(); i++){
    totalHours += ceil((double)arr[i]/hourly);
  }
  return totalHours;
}

int noOfBananaKokoCanEat(vector<int> &arr, int h) { 
    int low = 1; //minimum no of banana he can eat per hour
    int high = *max_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalHours = totlaHour(arr, mid);
        if(totalHours <= h){
          ans = mid;
          high = mid - 1;
        }else
          low = mid + 1;
    }

    return ans;
}
int main() {
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;

    int ans = noOfBananaKokoCanEat(arr, h);

    cout << "Minimum eating speed: " << ans << endl;

    return 0;
}
