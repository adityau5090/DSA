// Kth largest element in array

#include <bits/stdc++.h>
using namespace std;

// we are going to use min heap
int findKthLargest(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int it: arr){
        min_heap.push(it);
        if(min_heap.size() > k){
            min_heap.pop();
        }
    }

    return min_heap.top();
}
// TC -> O(nlogn)

int main() {

    vector<int> arr = {3,2,1,5,6,4};
    int k=2;
    cout<<k<<"th largest element : "<<findKthLargest(arr,k);

    return 0;
}