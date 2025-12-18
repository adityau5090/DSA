// Note: Binary search con be applied only on sorted array

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &vec,int target){
    int n = vec.size();
    int st = 0, end = n-1;
    while(st<=end){
        int mid = (st+end)/2;
        if(vec[mid] == target) return mid;
        else if(target > vec[mid]) st=mid+1;
        else end=mid-1;
    }
    return -1;
}
int main(){
    vector<int> vec= {1,2,3,4,5,6};
    int ans = binarySearch(vec,5);
    if(ans == (-1)) cout<<"Target not found!";
    else cout<<"Target found at idx: "<<ans;
return 0;
}