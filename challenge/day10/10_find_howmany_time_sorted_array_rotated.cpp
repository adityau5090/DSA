#include<iostream>
#include<vector>
#include<climits>
using namespace std;
    int minimum(vector<int> vec){
        int low = 0, high = vec.size()-1;
        int ans = INT_MAX;
        int index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(vec[low] <= vec[high]){
                if(vec[low] < ans){
                    index = low;
                    ans = vec[low];
                }
                break;
            }

            if(vec[low] <= vec[mid]){
                if(vec[low] <= ans){
                    index = low;
                    ans = vec[low];
                }
                low = mid + 1;
            }else{
                high = mid - 1;
                if(vec[mid] < ans){
                    index = mid;
                    ans = vec[mid];
                }
            }
        }
        return index;
    }
int main(){
    vector<int> vec = {4,5,1,2,3};
    cout<<minimum(vec);
return 0;
}