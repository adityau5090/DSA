#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// brute_force approach
// Time complexity = O(nlogn)

int secondLargestEle(int arr[], int size)
{
    sort(arr, arr + size);
    int largest = arr[size - 1];
    int secLargest = INT_MIN;
    // now imagine my arr = [2,4,5,6,7,7]; // he here 7 is not second largest
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > secLargest && arr[i] != largest)
        {
            secLargest = arr[i];
        }
    }
    return secLargest;
}

// better approach
// time complexity = O(2n)

int secondLargest(int arr[], int size)
{
    int largest = INT_MIN;
    int secLargest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > secLargest && arr[i] != largest)
        {
            secLargest = arr[i];
        }
    }
    return secLargest;
}

// optimal approach
// time complexity = O(n)

int secondLargestElement(int arr[], int size){
    int secLargest = INT_MIN;
    int largest = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > largest){
            secLargest = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }
    return secLargest;
}

int main()
{
    int arr[] = {23, 4, 53, 66, 66, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << secondLargestElement(arr, size);
    return 0;
}