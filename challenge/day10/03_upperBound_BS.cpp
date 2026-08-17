// Upper bound in binary search means smallest index such that arr[ind] >  n
// Ex [3,5,8,10] and n=8 so upper bound is 3 because on index 3-> 10 which is >= n
// Ex [3,5,8,16] and n=20 so upper bound is 4 last hypothetical index which not exist
// Ex [3,5,8,15,15,16] and n=15 so upper bound is 5

#include <iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> vec, int target)
{
    int low = 0, high = vec.size() - 1;
    int ans = vec.size(); // hypothetical index
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (vec[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {1, 5, 7, 19, 20, 20, 23, 34, 89};
    cout<<upperBound(vec, 20);  //expecting 6
    return 0;
}