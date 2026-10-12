////   Sort Colors

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////   Three Pointer Approach (Dutch National Flag algorithm)
void sortColors(vector<int> &arr){
    int low=0, mid=0, high=arr.size()-1;

    while(mid <= high){
        if(arr[mid] == 1) mid++;
        else if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {

    vector<int> arr = {2,0,2,1,1,0};
    sortColors(arr);
    for(int it: arr){
        cout<<it<<",";
    }

    return 0;
}