//////////          Search Insert Position

#include <bits/stdc++.h>
using namespace std;

// int searchIndex(vector<int> &arr, int target){
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i] >= target){
//             return i;
//         }
//     }
//     return arr.size();
// }
/////// TC -> O(n)

/////////////////////////////     Binary Search
int searchIndex(vector<int> & arr, int target){
    int low=0, high= arr.size()-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
///////// TC -> o(logn)

int main() {

    vector<int> arr = {1,3,5,6};
    cout<<"Index Position : "<<searchIndex(arr,7);

    return 0;
}