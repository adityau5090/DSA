#include<iostream>
#include<vector>
using namespace std;

    bool checkSorted(vector<int> arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i] >= arr[i-1]){}
            else{
                return false;
            }
        }
        return true;
    }
int main(){
    vector<int> arr = {1,3,5,17,9,23};
    cout << (checkSorted(arr) ? "Sorted" : "Not-Sorted");
    return 0;
}