// Binary search is performed on Sorted Array

#include <iostream>
#include <vector>
using namespace std;
// Iterative Code
int binarySearchIt(vector<int> vec, int target)
{
    int low = 0, high = vec.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Recursive code
int binarySearchRe(vector<int> vec, int target, int low, int high){
    if(low > high) return -1;

    int mid = low + (high - low)/2;

    if(vec[mid] == target){
         return mid;
    }else if(vec[mid] < target) {
        return binarySearchRe(vec, target, mid+1, high);
    }else{
        return binarySearchRe(vec, target, low, mid-1);
    }
}
int main()
{
    vector<int> vec = {1, 5, 7, 19, 23, 34, 89};
    // int ans = binarySearchIt(vec, 14);
    int ans = binarySearchRe(vec, 19, 0, vec.size()-1);
    if (ans != -1)
    {
        cout << "Found at index : " << ans << endl;
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}