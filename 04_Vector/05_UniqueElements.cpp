// find unique elements from vectors 

#include<iostream>
#include<vector>
using namespace std;

void unique(vector<int> vec ){
    vector<int> res;
    for(int i=0; i<vec.size()-1; i++){
        bool found = false;
        for(int j=i+1; j<vec.size(); j++){
            if(vec[i] == vec[j]){
                found = true;
                break;
            }
        }
        if(!found) res.push_back(vec[i]);
    }
    for(int i : res){
        cout<<i<<"\t";
    }
}

int main(){
    vector<int> vec = {1,4,5,1};
    unique(vec);
}