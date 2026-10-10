//// Baseball Game

#include <bits/stdc++.h>
using namespace std;

int calculatePoints(vector<string>  &operations){
    vector<int> ops;

    for(int i=0; i<operations.size(); i++){
        if(operations[i] == "C"){
            ops.pop_back();
        }else if(operations[i] == "D"){
            ops.push_back(ops.back() * 2);
        }else if(operations[i] == "+"){
            ops.push_back(ops[ops.size()-1] + ops[ops.size()-2]);
        }else{
            ops.push_back(stoi(operations[i]));
        }
    }

    int sum =0;
    for(int i : ops){
        sum += i;
    }

    return sum;
}
// TC -> O(2n)   SC -> O(n)


int main() {

    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    cout<<"Sum : "<<calculatePoints(ops);

    return 0;
}