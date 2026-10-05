#include <bits/stdc++.h>
using namespace std;

int noOfPainter(vector<int> &arr, int work){
    int painter = 1, workCount = 0;

    for(int i=0; i<arr.size(); i++){
        if(workCount + arr[i] <= work){
            workCount += arr[i];
        }else{
            workCount = arr[i];
            painter++;
        }
    }
    return painter;
}
int painterPartition(vector<int> &arr, int painter){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for(int i=low; i<= high; i++){
        int painters = noOfPainter(arr, i);
        if(painters <= painter){
            return i;
        }
    }
    return -1;
}


int painterPartitions(vector<int> &arr, int painter){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low+high)/2;

        int painters = noOfPainter(arr,mid);
        if(painters <= painter){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main() {

    vector<int> arr = {10, 20 ,30, 40};
    cout<<painterPartitions(arr, 2);
    return 0;
}