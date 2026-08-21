#include<iostream>
#include<vector>
#include<climits>
using namespace std;
    int minimum(vector<int> vec){
        int low = 0, high = vec.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(vec[low] <= vec[high]){
                ans = min(ans,vec[low]);
                break;
            }

            if(vec[low] <= vec[mid]){
                ans = min(ans, vec[low]);
                low = mid + 1;
            }else{
                high = mid - 1;
                ans = min(ans,vec[mid]);
            }
        }
        return ans;
    }
int main(){
    vector<int> vec = {4,5,1,2,3};
    cout<<minimum(vec);
return 0;
}