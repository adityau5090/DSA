#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> vec, int target)
{
    int low = 0, high = vec.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(vec[low]  == vec[mid] && vec[mid] == vec[high]){
            low++;
            high--;
            continue;
        }

        if(vec[mid] == target)
        {
            return mid;
        }
        // left half sorted
        else if (vec[low] <= vec[mid])
        {
            if (vec[low] <= target && target <= vec[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (vec[mid + 1] <= target && target <= vec[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {10, 13, 15, 2, 5, 5,5,7, 9};
    cout << "Index : " << search(vec, 5);
    return 0;
}