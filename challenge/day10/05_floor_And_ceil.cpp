// floor -> largest no in array <= x
// ceil -> smallest no in array >= x
// ex - [10,20,30,40,50]  x=25
//  floor = 20, ceil = 30

#include <iostream>
#include <vector>
using namespace std;
int floor(vector<int> vec, int x)
{
    int low = 0, high = vec.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (vec[mid] <= x)
        {
            ans = vec[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int ceil(vector<int> vec,int x){
    int low = 0, high = vec.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (vec[mid] >= x)
        {
            ans = vec[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
void floorAndceil(vector<int> vec,int x){
    int floorAns = floor(vec,x);
    int ceilAns = ceil(vec,x);
    cout<<"Floor :"<<floorAns<<endl;
    cout<<"Ceil :"<<ceilAns<<endl;
}
int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};
    floorAndceil(vec, 25
    );
    return 0;
}