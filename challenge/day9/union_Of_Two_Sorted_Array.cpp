// brute force approach

// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;
// vector<int> unionOfArray(int arr1[], int n1, int arr2[], int n2)
// {
//     set<int> st;
//     for (int i = 0; i < n1; i++)
//     {
//         st.insert(arr1[i]);
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         st.insert(arr2[i]);
//     }
//     vector<int> unionArray;
//     for (auto it : st)
//     {
//         unionArray.push_back(it);
//     }
//     return unionArray;
// }
// int main()
// {
//     int arr1[] = {1, 2, 3, 4};
//     int arr2[] = {3, 4, 5, 6};

//     vector<int> result = unionOfArray(arr1, 4, arr2, 4);

//     for (int x : result)
//     {
//         cout << x << " ";
//     }
//     return 0;
// }

// Time complexity = O(n1.logn) + O(n2.logn) + O(n1+n2)
// Space complexity = O(n1+n2) + O(n1+n2)-> but this is only to return the answer

////// Optimal approach
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> unionOfArray(int arr1[], int n1, int arr2[], int n2)
{
    vector<int> unionArray;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            if(unionArray.size() == 0 || unionArray.back() != arr1[i]){
                unionArray.push_back(arr1[i]);
            }
            i++;
        }else{
            if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
        }

    }
    while(i<n1){
        if(unionArray.size() == 0 || unionArray.back() != arr1[i]){
                unionArray.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}
int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};

    vector<int> result = unionOfArray(arr1, 4, arr2, 4);

    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}

// time complexity = O(n1+n2)
// space complexity = O(n1+n2) -> for return only