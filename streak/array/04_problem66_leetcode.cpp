///////// Plus One

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> & digits){
    for(int i = digits.size()-1; i>=0; i--){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }else{
            digits[i] = 0;   
        }
    }
    digits.insert(digits.begin(),1);
    return digits;
}
int main() {

    vector<int> arr = {4,3,2,1};
    vector<int> res = plusOne(arr);
    for(int i: res){
        cout<<i<<",";
    }

    return 0;
}