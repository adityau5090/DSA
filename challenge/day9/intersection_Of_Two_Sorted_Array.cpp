#include<iostream>
#include<vector>
using namespace std;
    vector<int> intersectionOfArray(int arr1[], int n1, int arr2[], int n2){
        int i=0, j=0;
        vector<int> ans;
        while(i<n1 && j<n2){
            if(arr1[i] < arr2[j]){
                i++;
            }else if(arr1[i] > arr2[j]){
                j++;
            }else{
                ans.push_back(arr1[i]);
                i++;
                j++;
                
            }
        }
        return ans;
    }
int main(){
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};

    vector<int> result = intersectionOfArray(arr1, 4, arr2, 4);

    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}

// Time complexity = O(n1 + n2)
// Space complexity = O(1) &&  O(n) for returning the answer