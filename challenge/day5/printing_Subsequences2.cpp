// printing subsequence whose sum is K - using recursion
// [1,2,1]  sum=2 => [1,1], [2]

#include<iostream>
#include<vector>
using namespace std;
    void printSubsequence(vector<int> arr, int sum, int i=0, vector<int> ans={}, int mysum = 0){
        if(i == arr.size()){
            if(mysum == sum){
                cout<<"[";
                for(int i : ans){
                    cout<<" "<<i<<" ";
                }
                cout<<"]\n";
            }
            return;
        }
        // take the current element
        ans.push_back(arr[i]);
        mysum+=arr[i];
        printSubsequence(arr,sum, i+1, ans, mysum);

        //don't take the current element

        ans.pop_back();
        mysum-=arr[i];
        printSubsequence(arr,sum,i+1,ans,mysum);
        
    }
int main(){
    vector<int> arr = {1,2,1};
    printSubsequence(arr,2);
return 0;
}