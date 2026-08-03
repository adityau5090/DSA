// In a given arr find out a how many time a specific element present
//  Ex -> [1,2,1,3,2] how many time 3 appears = (3 -> 1 times)

#include<iostream>
#include<vector>
using namespace std;
    int hashAndSearcrh(vector<int> arr, int target){
        vector<int> hashArray(12,0); // it create 12 size of array assigned with zero 
        // I took 12 because I konw that my array should be less than 12
        for(int i=0; i<arr.size(); i++){
            hashArray[arr[i]] += 1;   
        }

        return hashArray[target];
    }
int main(){
    vector<int> arr = {1,3,2,1,3};
    cout<<hashAndSearcrh(arr, 2);
return 0;
}


// now let do same for characters