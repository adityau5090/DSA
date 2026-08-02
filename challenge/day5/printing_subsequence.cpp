// print subsequence in recursion

// [3,1,2] = [],[1],[2],[3],[3,1],[1,2],[3,2],[3,1,2]

#include<iostream>
#include<vector>
using namespace std;
    void printSubSequence(int i, vector<int> arr, vector<int> res = {}){
        if(i >= arr.size()){
            cout<<"[";
            for(int i : res){
                cout<<" "<<i<<" ";
            }
            cout<<"],";
            return;
        }

        // pick the particular index into subsequence
        res.push_back(arr[i]);
        printSubSequence(i+1, arr,res);

        // don't pick the particular index into subsequence
        res.pop_back();
        printSubSequence(i+1, arr,res);
    }
int main(){
    vector<int> arr = {3,1,2};
    printSubSequence(0, arr);
return 0;
}

// time complexity -> 
//     so for every index we have to option pick or not pick so 2^n
//     ans to print every subsequnce we take n times                                    s
//     so overall time-complexity = 2^n * n = 2^n

// space complexity is O(n)