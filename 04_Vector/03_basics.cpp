#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1 = {1,4,6,8};

    for(int val: vec1){   // for-each loop
        cout<<val<<"\t";
    }
    cout<<"\n";
    
    vector<char> vec2 = {'a','b','c','d'};
    for(char val: vec2){
        cout<<val<<"\t";
    }
return 0;
}